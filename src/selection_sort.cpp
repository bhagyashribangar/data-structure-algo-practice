// Selection sort

#include <iostream>
using namespace std;

void selectionSort(int A[], int N) {
    for (int i = 0; i < N - 1; ++i) {
        int min_idx =  i;
        for (int j = i + 1; j < N; ++j) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(A[min_idx], A[i]);
        }
    }
}

int main() {
    int A[] = {12, 11 ,13, 5, 6};
    int N = sizeof(A)/sizeof(A[0]);

    selectionSort(A, N);

    cout << "Sorted array is: ";
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}