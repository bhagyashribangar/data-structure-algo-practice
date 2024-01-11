// Quick sort implementation

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& A, int start, int end) {
    int pivot = A[end];
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (A[j] < pivot) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[end]);
    return i+1;
}

void quickSort(vector<int>& A, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(A, start, end);

        quickSort(A, start, pivotIndex - 1);
        quickSort(A, pivotIndex + 1, end);
    }
}

int main() 
{
    vector<int> A = {12, 3, 45, 22, 39, 5};
    cout << "Input array is: ";
    for (int i : A) {
        cout << i << " ";
    }

    quickSort(A, 0, A.size() - 1);

    cout << "\nSorted array is: ";
    for (int i : A) {
        cout << i << " ";
    }

    return 0;
}