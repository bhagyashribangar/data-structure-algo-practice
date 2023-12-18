// Bubble sort

#include <iostream>
using namespace std;

void bubbleSort(int A[], int N) {
    for (int i = 0; i < N -1; ++i) {
        int swapped = 0;
        for (int j = 0; j < N - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                //swap(A[j], A[j+1]);
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main()
{
    int A[] = {12, 11 ,13, 5, 6};
    int N = sizeof(A)/sizeof(A[0]);

    bubbleSort(A, N);

    cout << "Sorted array is: ";
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}