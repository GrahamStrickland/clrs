// Brute-Force-Maximum-Subarray algorithm from ex. 4.1-2 p.74 of CLRS 3e

#include <chrono>
#include <iostream>

int *findMaximumSubarray(int A[], int len);

int main(int argc, char *argv[]) {
  int numStocks = 17, repetitions = 20;
  int stockPrices[] = {100, 113, 110, 85,  105, 102, 86, 63, 81,
                       101, 94,  106, 101, 79,  94,  90, 97};

  std::cout << "Daily recorded stock prices over " << numStocks << " days:\n";

  for (int i = 0; i < numStocks; i++)
    std::cout << "$" << stockPrices[i] << (i == numStocks - 1 ? "\n" : ", ");

  int dailyChanges[numStocks - 1];
  for (int i = 0; i < numStocks - 1; i++)
    dailyChanges[i] = stockPrices[i + 1] - stockPrices[i];

  std::chrono::time_point<std::chrono::steady_clock> startTime =
      std::chrono::steady_clock::now();
  int *maximumSubarray = new int[3];
  for (int i = 0; i < repetitions; i++)
    maximumSubarray = findMaximumSubarray(dailyChanges, numStocks - 1);
  auto endTime = std::chrono::steady_clock::now();

  std::cout << "\nMaximum values in changing daily stock price: ";
  for (int i = maximumSubarray[0]; i <= maximumSubarray[1]; i++)
    std::cout << "Change from day " << i << " to day " << i + 1 << ": "
              << dailyChanges[i] << "\n";
  std::cout << "\nResulting Value = $" << maximumSubarray[2]
            << "\nRunning time of program: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime -
                                                                    startTime)
                       .count() /
                   1000. / repetitions
            << "ns\n";

  delete[] maximumSubarray;

  return EXIT_SUCCESS;
}

int *findMaximumSubarray(int A[], int len) {
  int *maximumSubarray = new int[3];
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
