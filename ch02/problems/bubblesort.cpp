// Bubble-Sort algorithm from p.2-2 on pg. 40 of CLRS 3e

#include <iostream>

void bubbleSort(int A[], int len);
void testBubbleSort(int A[], int len);

int main(int argc, char *argv[]) {
    int A[] = {5, 2, 4, 6, 1, 3};
    int B[] = {31, 41, 59, 26, 41, 58};
    int C[] = {6, 5, 4, 3, 2, 1};
    int D[] = {5, 2, 4, 7, 1, 3, 2, 6};
    int E[] = {3, 41, 52, 26, 38, 57, 9, 49};

    int len = 6;
    testBubbleSort(A, len);
    testBubbleSort(B, len);
    testBubbleSort(C, len);

    len = 8;
    testBubbleSort(D, len);
    testBubbleSort(E, len);

    return EXIT_SUCCESS;
}

void bubbleSort(int A[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j >= i + 1; j--) {
            if (A[j] < A[j-1]) {
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
    }
}

void testBubbleSort(int A[], int len) {
    std::cout << "Array before Bubble-Sort: ";
    for (int i = 0; i < len; i++)
        std::cout << A[i] << ' ';
    std::cout << '\n';
    
    bubbleSort(A, len);
        
    std::cout << "Array before Bubble-Sort: ";
    for (int i = 0; i < len; i++)
        std::cout << A[i] << ' ';
    std::cout << "\n\n";
}
