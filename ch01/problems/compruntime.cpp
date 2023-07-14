// Problem p1-1 from p.14 of CLRS 3e

#include <iostream>
#include <cmath>


double factorial(double n);

int main(int argc, char *argv[]) {
    double runtimes[] = {1.0, 6.0E1, 3.6E3, 8.64E4, 2.592E6, 3.1536E7, 3.1536E9};

    std::cout << "Comparison of running times for the largest problem size n "
              << "of a problem that can be solved in time t, assuming that "
              << "the algorithm to solve the problem takes f(n) microseconds:\n\n"
              << "------------------------------------------------------------"
              << "------------------------------------------------------------"
              << "----------------------------------------------------\nf(n)\t\t"
              << "1 second\t\t1 minute\t\t1 hour\t\t\t1 day\t\t\t1 month\t\t\t"
              << "1 year\t\t\t1 century\n-------------------------------------"
              << "------------------------------------------------------------"
              << "------------------------------------------------------------"
              << "---------------\n";

    std::cout << "lg(n)\t\t";
    for (double time : runtimes)
        std::cout << time << "\t\t" << std::floor(std::pow(2, time * 1E6));
    std::cout << "\n";
    
    std::cout << "sqrt(n)\t\t";
    for (double time : runtimes)
        std::cout << time << "\t\t" << std::floor(std::pow(time * 1E6, 2));
    std::cout << "\n";
    
    std::cout << "n\t\t";
    for (double time : runtimes)
        std::cout << time << "\t\t" << std::floor(time * 1E6);
    std::cout << "\n";
    
    std::cout << "n(lg(n))\t";
    for (double time : runtimes)
        std::cout << time << "\t\t" 
                  << std::floor(
                        (std::log(time * 1E6) / std::log(2)) / (time * 1E6)
        );
    std::cout << "\n";
    
    std::cout << "n^2\t\t";
    for (double time : runtimes)
        std::cout << time << "\t\t" << std::floor(std::pow(time * 1E6, 0.5));
    std::cout << "\n";
    
    std::cout << "n^3\t\t";
    for (double time : runtimes)
        std::cout << time << "\t\t" << std::floor(std::pow(time * 1E6, 1.0/3.0));
    std::cout << "\n";
    
    std::cout << "2^n\t\t";
    for (double time : runtimes)
        std::cout << time << "\t\t" << std::floor(
                        ((std::log(time * 1E6) / std::log(2)))
        );
    std::cout << "\n";
    
    std::cout << "n!\t\t";
    for (double time : runtimes)
        std::cout << time << "\t\t" << std::floor(factorial(time * 1E6));

    std::cout << "\n----------------------------------------------------------"
              << "------------------------------------------------------------"
              << "-------------------------------------------------------\n";

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
