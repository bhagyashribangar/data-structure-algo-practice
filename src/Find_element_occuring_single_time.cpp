// Given array with each elements repeating two times except one element which occurs once
// Find the element which occurs only one time

#include<iostream>
using namespace std;

int findElement(int A[], int l, int r)
{
    if (l <= r) {
		int m = l + (r - l) / 2;
		if (A[m] != A[m-1] && A[m] != A[m+1]) {
            return A[m];
        } else if (A[m] == A[m-1]) {
            return findElement(A, l, m-1);
        } else {
            return findElement(A, m+1, r);
        }
	}

	return -1;
}

int main()
{
    int A[] = {2, 3, 3, 4, 4};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Element occuring single times is: " << findElement(A, 0, n - 1);
    // Currently this is not giving correct result for input {2, 2, 3, 3, 4}, need to fix
    return 0;
}
