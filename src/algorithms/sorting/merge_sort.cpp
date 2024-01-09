// Merge-Sort algorithm from p.31-34 of CLRS 3e

#include <iostream>

void merge(int A[], int p, int q, int r);
void mergeSort(int A[], int p, int r);
void testMergeSort(int A[], int len);

int main(int argc, char *argv[]) {
    int A[] = {5, 2, 4, 6, 1, 3};
    int B[] = {31, 41, 59, 26, 41, 58};
    int C[] = {6, 5, 4, 3, 2, 1};
    int D[] = {5, 2, 4, 7, 1, 3, 2, 6};
    int E[] = {3, 41, 52, 26, 38, 57, 9, 49};

    int len = 6;
    testMergeSort(A, len);
    testMergeSort(B, len);
    testMergeSort(C, len);

    len = 8;
    testMergeSort(D, len);
    testMergeSort(E, len);

    return EXIT_SUCCESS;
}

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    
    int L[n1 + 1], R[n2 + 1];
    
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + j + 1];
    
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    
    int i = 0, j = 0;
    
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void testMergeSort(int A[], int len) {
    std::cout << "Array before Merge-Sort: ";
    for (int i = 0; i < len; i++)
        std::cout << A[i] << ' ';
    std::cout << '\n';
    
    mergeSort(A, 0, len-1);
    
    std::cout << "Array after Merge-Sort: ";
    for (int i = 0; i < len; i++)
        std::cout << A[i] << ' ';
    std::cout << "\n\n";
}
