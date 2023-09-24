// Combination of brute-force and divide-and-conquer Maximum-Subarray algorithms
// from ex. 4.1-3 p.74 of CLRS 3e
    
#include <chrono>
#include <iostream>

int* findMaxCrossingSubarray(int A[], int low, int mid, int high);
int* bruteForceFindMaximumSubarray(int A[], int len);
int* findMaximumSubarray(int A[], int low, int high);

int main(int argc, char *argv[]) {
    int numStocks = 17, repetitions = 20;
    int stockPrices[] = { 100, 113, 110, 85, 105,
                          102, 86, 63, 81, 101, 
                          94, 106, 101, 79, 94, 
                          90, 97 };

    std::cout << "Daily recorded stock prices over "
              << numStocks << " days:\n";

    for (int i = 0; i < numStocks; i++)
        std::cout << "$" << stockPrices[i] 
                  << (i == numStocks - 1 ? "\n" : ", ");

    int dailyChanges[numStocks - 1];
    for (int i = 0; i < numStocks - 1; i++)
        dailyChanges[i] = stockPrices[i+1] - stockPrices[i];

    std::chrono::time_point<std::chrono::steady_clock> startTime =  
            std::chrono::steady_clock::now();
    int* maximumSubarray = new int[3];
    for (int i = 0; i < repetitions; i++)
        maximumSubarray = findMaximumSubarray(dailyChanges, 0, numStocks - 2);
    auto endTime = std::chrono::steady_clock::now();

    std::cout << "\nMaximum values in changing daily stock price: ";
    for (int i = maximumSubarray[0]; i <= maximumSubarray[1]; i++)
        std::cout << "Change from day " << i << " to day " << i + 1 
                  << ": " << dailyChanges[i] << "\n";
    std::cout << "\nResulting Value = $" << maximumSubarray[2]
              << "\nRunning time of program: " 
              << std::chrono::duration_cast<std::chrono::nanoseconds>(
                        endTime - startTime
                ).count() / 1000. / repetitions
              << "ns\n";

    delete [] maximumSubarray;

    return EXIT_SUCCESS;
}

int* findMaxCrossingSubarray(int A[], int low, int mid, int high) {
    int* maxCrossingSubarray = new int[3];
    int leftSum = INT_MIN, sum = 0;

    for (int i = mid; i >= low; i--) {
        sum = sum + A[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxCrossingSubarray[0] = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    
    for (int j = mid + 1; j <= high; j++) {
        sum = sum + A[j];
        if (sum > rightSum) {
            rightSum = sum;
            maxCrossingSubarray[1] = j;
        }
    }

    maxCrossingSubarray[2] = leftSum + rightSum;

    return maxCrossingSubarray;
}

int* bruteForceFindMaximumSubarray(int A[], int len) {
    int* maximumSubarray = new int[3];
    int low = 0, high = 1, sum = 0;
    maximumSubarray[0] = low;
    maximumSubarray[1] = high;
    maximumSubarray[2] = sum;

    while (low < len - 2) {
        while (high < len - 1) {
            sum += A[high];
            if (sum > maximumSubarray[2]) {
                maximumSubarray[0] = low;
                maximumSubarray[1] = high;
                maximumSubarray[2] = sum;
            }
            high++;
        }
        low++;
        high = low + 1;
        sum = 0;
    }

    return maximumSubarray;
}

int* findMaximumSubarray(int A[], int low, int high) {
    int* maximumSubarray = new int[3];
    int* leftSubarray = new int[3];
    int* rightSubarray = new int[3]; 
    int* crossSubarray = new int[3];

    maximumSubarray[0] = low;
    maximumSubarray[1] = high;
    maximumSubarray[2] = A[low];

    if (high == low) {
        delete [] leftSubarray;
        delete [] rightSubarray;
        delete [] crossSubarray;

        return maximumSubarray; // Base case: only one element
    } else if (high - low < 20) {   // For n_0 < 20, use faster brute-force approach
        delete [] maximumSubarray;
        delete [] leftSubarray;
        delete [] rightSubarray;
        delete [] crossSubarray;

        return bruteForceFindMaximumSubarray(A, high - low + 1);
    } else {  // Recursive algorithm for n_0 >= 20.
        int mid = (low + high) / 2;

        leftSubarray = findMaximumSubarray(A, low, mid);
        rightSubarray = findMaximumSubarray(A, mid+1, high);
        crossSubarray = findMaxCrossingSubarray(A, low, mid, high);

        if (leftSubarray[2] >= rightSubarray[2] 
            && leftSubarray[2] >= crossSubarray[2]) {
            delete [] rightSubarray;
            delete [] crossSubarray;
            return leftSubarray;
        } else if (rightSubarray[2] >= leftSubarray[2]
            && rightSubarray[2] >= crossSubarray[2]) {
            delete [] leftSubarray;
            delete [] crossSubarray;
            return rightSubarray;
        } else {
            delete [] leftSubarray;
            delete [] rightSubarray;
            return crossSubarray;
        }
    }
}
