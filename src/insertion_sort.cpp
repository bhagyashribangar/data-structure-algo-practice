// Insertion sort

#include <iostream>
using namespace std;

void insersionSort(int A[], int N) {
    int i, j, key;
    for (i = 1; i < N; ++i) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = key;
    }
}

int main()
{
    int A[] = {12, 11 ,13, 5, 6};
    int N = sizeof(A)/sizeof(A[0]);

    insersionSort(A, N);

    cout << "Sorted array is: ";
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}