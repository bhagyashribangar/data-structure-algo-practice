// Binary search: Recursion
#include<iostream>
using namespace std;

int binarySearch(int A[], int l, int r, int val)
{
	if (l <= r) {
		int m = l + (r - l) / 2;
		if (A[m] == val) {
            return m;
        } else if (A[m] < val) {
            return binarySearch(A, m + 1, r, val);
        } else {
            binarySearch(A, l, m-1, val);
        }
	}

	return -1;
}

int main()
{
	int A[] = { 5, 7, 9, 12, 20 };
	int val = 20;
	int n = sizeof(A) / sizeof(A[0]);
	int result = binarySearch(A, 0, n - 1, val);
	(result == -1) ? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
}
