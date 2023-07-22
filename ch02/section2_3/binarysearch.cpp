// Binary-Search algorithm from ex. 2.3-5 from p.39 of CLRS 3e

#include <iostream>

void testBinarySearch(int A[], int len, int nu);
int binarySearch(int A[], int len, int nu);

int main(int argc, char *argv[]) {
    int A[] = {26, 31, 41, 41, 58, 59};
    int len = 6;
    int nu = 31;

    testBinarySearch(A, len, nu);
    
    nu = 32;
    testBinarySearch(A, len, nu);
    
    int B[] = {1, 4, 5, 7, 19, 28, 45, 92};
    len = 8;
    nu = 92;
    testBinarySearch(B, len, nu);
    
    nu = 101;
    testBinarySearch(B, len, nu);

    return EXIT_SUCCESS;
}

void testBinarySearch(int A[], int len, int nu) {
    std::cout << "Array values: ";
    for (int i = 0; i < len; i++)
        std::cout << A[i] << ' ';
    std::cout << "\nnu = " << nu << "\n";
    
    std::cout << "Array does" 
              << (binarySearch(A, len, nu) == -1 ? " not " : " ") 
              << "contain " << nu << ".\n\n";
}

int binarySearch(int A[], int len, int nu) {
    int low = 0, high = len - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nu == A[mid])
            return mid;
        else if (nu > A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
