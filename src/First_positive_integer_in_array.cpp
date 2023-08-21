// Given an unsorted array find the 1st positive integer which is missing
// TC: O(n), SC: O(1)
#include<iostream>
#include<algorithm>
using namespace std;

int firstPositiveInteger(int A[], int n)
{
    int i = 0;
    while(i < n) {
        if (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]) {
            swap(A[i], A[A[i]-1]);
        } else {
            ++i;
        }
    }

    for (int i=0; i<n; ++i) {
        if(A[i] != i+1) {
            return i+1;
        }
    }
    return 0;
}

int main()
{
    int A[] = {-5, 0, 6, 2, 3, 7, 9, 1};
	int n = sizeof(A) / sizeof(A[0]);

	cout << "First positive integer in array is: " << firstPositiveInteger(A, n) << endl;
	return 0;
}