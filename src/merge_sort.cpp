// Merge sort
// TC: O(Nlog(N)), SC: O(N)
#include <iostream>
using namespace std;

void merge(int A[], int const l, int const m, int const r) 
{
    int const n1 = m - l + 1;
    int const n2 = r - m;

    auto *lArr = new int[n1];
    auto *rArr = new int[n2];

    for (auto i = 0; i < n1; i++) {
        lArr[i] = A[l + i];
    }

    for (auto j = 0; j < n2; j++){
        rArr[j] = A[m + 1 + j];
    }
        

    // Maintain current index of sub-arrays and main array
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (lArr[i] <= rArr[j]) {
            A[k] = lArr[i];
            i++;
        } else {
            A[k] = rArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = lArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = rArr[j];
        j++;
        k++;
    }

    delete[] lArr;
    delete[] rArr;
}

void mergeSort(int A[], int const l, int const r) 
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);

        // Merge the sorted subarrays
        merge(A, l, m, r);
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
    cout << A[i] << " ";
}

int main()
{
    int A[] = {-5, 0, 6, 2, 3, 7, 9, 1};
	int n = sizeof(A) / sizeof(A[0]);

    mergeSort(A, 0, n - 1);
	cout << "Sorted array is: ";
    printArray(A, n);

	return 0;
}