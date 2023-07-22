// Linear-Search algorithm from ex2.1-3 p.22 of CLRS 3e

#include <iostream> 

void testLinearSearch(int A[], int len, int nu);
int linearSearch(int A[], int len, int nu);

int main(int argc, char *argv[]) {
    int A[] = {31, 41, 59, 26, 41, 58};
    int len = 6, nu = 31;

    testLinearSearch(A, len, nu);
    
    nu = 32;
    testLinearSearch(A, len, nu);
    
    int B[] = {1, 4, 39, 99, 100, 20};
    nu = 39;
    testLinearSearch(B, len, nu);
    
    nu = 101;
    testLinearSearch(B, len, nu);

    return EXIT_SUCCESS;
}

void testLinearSearch(int A[], int len, int nu) {
    std::cout << "Array values: ";
    for (int i = 0; i < len; i++)
        std::cout << A[i] << ' ';
    std::cout << "\nnu = " << nu << "\n";
    
    std::cout << "Array does" 
              << (linearSearch(A, len, nu) == -1 ? " not " : " ") 
              << "contain " << nu << ".\n\n";
}

int linearSearch(int A[], int len, int nu) {
    int j = 0;
    
    while (j != len) {
        if (A[j] == nu) 
            return j;
        else
            j += 1;
    }

    return -1;
}
