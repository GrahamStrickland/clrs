// Problem p1-1 from p.14 of CLRS 3e

#include <cmath>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

double inverse_nlogn(double x);
double inverse_factorial(double x);

int main(int argc, char* argv[]) {
    using namespace std::chrono;

    std::vector<std::chrono::duration<long long>> runtimes = {1s, 1min, 1h, 
        std::chrono::days(1), std::chrono::weeks(1), 
        std::chrono::years(1), std::chrono::years(100)};

    std::cout << "Comparison of running times for the largest problem size n "
              << "of a problem that can be solved in time t, assuming that\n"
              << "the algorithm to solve the problem takes f(n) microseconds:\n"
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
        double smallest_n = std::floor(inverse_nlogn(
            std::chrono::duration<double>(time).count() * 1E6
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
        double smallest_n = std::floor(inverse_factorial(
            std::chrono::duration<double>(time).count() * 1E6
        ));
        std::cout << "\t" << std::setw(12) << smallest_n; 
    }

    std::cout << "\n-----------------------------------------------------------"
              << "---------------------------------------------------------\n";

    return EXIT_SUCCESS;
}

double inverse_nlogn(double x) {
    uint8_t max_iters = 10;
    double a_0 = x / std::log2(x), a_1 = 0.0;

    for (uint8_t i = 0; i < max_iters; ++i) {
        a_1 = a_0 - (
            (a_0 * std::log2(a_0) - x) 
            / ((1.0 / std::log(2.0)) + std::log2(a_0))
        ); 
        if (abs((a_1 * std::log2(a_1)) - (a_0 * std::log2(a_0))) < 1)
            return a_1;
        else
            a_0 = a_1;
    }

    return a_1;
}

double inverse_factorial(double x) {
    return x;
}
