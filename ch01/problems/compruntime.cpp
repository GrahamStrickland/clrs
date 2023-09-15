// Problem p1-1 from p.14 of CLRS 3e

#include <cmath>
#include <iomanip>
#include <iostream>

double factorial(double n);

int main(int argc, char* argv[]) {
    double runtimes[] = {1.0, 6.0E1, 3.6E3, 8.64E4, 2.592E6, 3.1536E7, 3.1536E9};

    std::cout << "Comparison of running times for the largest problem size n "
              << "of a problem that can be solved in time t, assuming that "
              << "the algorithm to solve the problem takes f(n) microseconds:\n\n"
              << "---------------------------------------------------------------"
              << "-----------------------------------------------------\n"
              << "f(n)\t" << std::setw(12) << "1 second\t" << std::setw(12) 
              << "1 minute\t" << std::setw(12) << "1 hour\t" << std::setw(12) 
              << "1 day\t" << std::setw(12) << "1 month\t" << std::setw(12)
              << "1 year\t" << std::setw(12) << "1 century\n"
              << "---------------------------------------------------------------"
              << "-----------------------------------------------------\n";

    std::cout << "lg(n)";
    for (double time : runtimes)
        std::cout << "\t" << std::setw(12) << std::floor(std::pow(2, time * 1E6));
    std::cout << "\n";
    
    std::cout << "sqrt(n)";
    for (double time : runtimes)
        std::cout << "\t" << std::setw(12) << std::floor(std::pow(time * 1E6, 2));
    std::cout << "\n";
    
    std::cout << "n";
    for (double time : runtimes)
        std::cout << "\t" << std::setw(12) << std::floor(time * 1E6);
    std::cout << "\n";
    
    std::cout << "nlg(n)";
    for (double time : runtimes)
        std::cout << "\t" << std::setw(12) 
                  << std::floor(
                        (std::log(time * 1E6) / std::log(2)) / (time * 1E6)
        );
    std::cout << "\n";
    
    std::cout << "n^2";
    for (double time : runtimes)
        std::cout << "\t" << std::setw(12) 
                  << std::floor(std::pow(time * 1E6, 0.5));
    std::cout << "\n";
    
    std::cout << "n^3";
    for (double time : runtimes)
        std::cout << "\t" << std::setw(12) 
                  << std::floor(std::pow(time * 1E6, 1.0/3.0));
    std::cout << "\n";
    
    std::cout << "2^n";
    for (double time : runtimes)
        std::cout << "\t" << std::setw(12) << std::floor(
                        ((std::log(time * 1E6) / std::log(2)))
        );
    std::cout << "\n";
    
    std::cout << "n!";
    for (double time : runtimes)
        std::cout << "\t" << std::setw(12) << std::floor(factorial(time * 1E6));

    std::cout << "\n-----------------------------------------------------------"
              << "---------------------------------------------------------\n";

    return EXIT_SUCCESS;
}

double factorial(double n) {
    int fact = (int)n, multiplier = (int)n;
    while (multiplier > 0) {
        fact = fact * multiplier;
        multiplier--;
    }
    
    return fact;
}
