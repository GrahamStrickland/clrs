// Non-recursive Find-Maximum-Subarray algorithm from ex. 4.1-5 on p.75 of CLRS 3e

#include <chrono>
#include <iostream>

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

int* findMaximumSubarray(int A[], int low, int high) {
    int* maxSubarray = new int[3];
    int j = low + 1;
    maxSubarray[0] = low;
    maxSubarray[1] = high;
    maxSubarray[2] = A[low] + A[j];
    int currentVal = maxSubarray[2];

    while (j < high) {
        currentVal = A[j+1];
        for (int i = j; i >= low; i--) {
            currentVal += A[i];
            if (maxSubarray[2] < currentVal) {
                maxSubarray[0] = i;
                maxSubarray[1] = j+1;
                maxSubarray[2] = currentVal;
            }
        }
        j++;
        currentVal = maxSubarray[2];
    }

    return maxSubarray;
}
