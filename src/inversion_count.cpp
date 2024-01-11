// Inversion Count using merge sort
// counting the number of inversion (pairs of indices (i, j)) such that i < j and arr[i] > arr[j]

#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& A, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = A[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = A[mid + 1 + j];
    }

    int inversionCount = 0;
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            A[k++] = leftArr[i++];
        } else {
            A[k++] = rightArr[j++];
            inversionCount += (n1 - i);
        }
    }
    while (i < n1) {
        A[k++] = leftArr[i++];
    }
    while (j < n2) {
        A[k++] = rightArr[j++];
    }
    return inversionCount;
}

int mergeSortAndCount(vector<int>& A, int left, int right)
{
    int inversionCount = 0;
    if (left < right) {
        int mid = left + (right-left)/2;

        // count inversion in left and right subarrays
        inversionCount += mergeSortAndCount(A, left, mid);
        inversionCount += mergeSortAndCount(A, mid + 1, right);

        // count inversion of mered array
        inversionCount += mergeAndCount(A, left, mid, right);
    }
    return inversionCount;
}

int main()
{
    vector<int> A = {1, 5, 3, 4, 2};

    int inversionCount = mergeSortAndCount(A, 0, A.size()-1);
    cout << "Inversion count is: " << inversionCount << endl;

    return 0;
}