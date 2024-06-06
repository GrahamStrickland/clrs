// Problem p1-1 from p.14 of CLRS 3e

#include <cmath>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

#include <boost/math/special_functions/lambert_w.hpp>

double factorial(double n);

int main(int argc, char* argv[]) {
    using namespace std::chrono;

    std::vector<std::chrono::duration<long long>> runtimes = {1s, 1min, 1h, 
        std::chrono::days(1), std::chrono::weeks(1), 
        std::chrono::years(1), std::chrono::years(100)};

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
    for (std::chrono::duration<long long> time : runtimes) {
        double smallest_n = std::floor(std::pow(
            2.0, 
            std::chrono::duration<double>(time).count()) * 1E6
        );
        std::cout << "\t" << std::setw(12) << smallest_n; 
    }
    std::cout << "\n";
    
    std::cout << "sqrt(n)";
    for (std::chrono::duration<long long> time : runtimes) {
        double smallest_n = std::floor(std::pow(
            std::chrono::duration<double>(time).count() * 1E6, 
            2.0
        ));
        std::cout << "\t" << std::setw(12) << smallest_n; 
    }
    std::cout << "\n";
    
    std::cout << "n";
    for (std::chrono::duration<long long> time : runtimes) {
        double smallest_n = std::floor(
            std::chrono::duration<double>(time).count() * 1E6
        );
        std::cout << "\t" << std::setw(12) << smallest_n; 
    }
    std::cout << "\n";
    
    std::cout << "nlg(n)";
    for (std::chrono::duration<long long> time : runtimes) {
        double smallest_n = std::floor(std::log(
            boost::math::lambert_w0(
                std::chrono::duration<double>(time).count() * 1E6
            )
        ));
        std::cout << "\t" << std::setw(12) << smallest_n; 
    }
    std::cout << "\n";
    
    std::cout << "n^2";
    for (std::chrono::duration<long long> time : runtimes) {
        double smallest_n = std::floor(std::pow(
            std::chrono::duration<double>(time).count() * 1E6, 
            0.5
        ));
        std::cout << "\t" << std::setw(12) << smallest_n; 
    }
    std::cout << "\n";
    
    std::cout << "n^3";
    for (std::chrono::duration<long long> time : runtimes) {
        double smallest_n = std::floor(std::pow(
            std::chrono::duration<double>(time).count() * 1E6,
            (1.0 / 3.0)
        ));
        std::cout << "\t" << std::setw(12) << smallest_n; 
    }
    std::cout << "\n";
    
    std::cout << "2^n";
    for (std::chrono::duration<long long> time : runtimes) {
        double smallest_n = std::floor(((
            std::log(
                std::chrono::duration<double>(time).count() * 1E6
            ) 
            / std::log(2.0)
        )));
        std::cout << "\t" << std::setw(12) << smallest_n;
    }
    std::cout << "\n";
    
    std::cout << "n!";
    for (std::chrono::duration<long long> time : runtimes) {
        double smallest_n = std::floor(factorial(
            std::chrono::duration<double>(time).count() * 1E6
        ));
        std::cout << "\t" << std::setw(12) << smallest_n; 
    }

    std::cout << "\n-----------------------------------------------------------"
              << "---------------------------------------------------------\n";

    return EXIT_SUCCESS;
}

double factorial(double n) {
    int fact = static_cast<int>(n), multiplier = static_cast<int>(n);

    while (multiplier > 0) {
        fact = fact * multiplier;
        multiplier--;
    }
    
    return fact;
}
