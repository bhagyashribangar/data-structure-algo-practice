// Given an unsorted array, find maximum distance between two consecutive number 
// if the given array is sorted
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

void findMaxDifference(int A[], int n)
{
    int max1 =-1;
    sort(A, A+n);
    for (int i=1; i<n; i++) {
        max1 = max(max1, A[i] - A[i-1]);
    }

    cout << "maximum difference between two consecutive number is: " << max1 << "\n";
}

int main()
{
    int A[] = {2, 6, 17, 12, 8, 7};
	int n = sizeof(A) / sizeof(A[0]);
    findMaxDifference(A, n);
    return 0;
}