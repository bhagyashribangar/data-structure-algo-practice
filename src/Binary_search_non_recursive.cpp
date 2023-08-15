// Binary search: Non-recursive loop
#include<iostream>
using namespace std;

int binarySearch(int A[], int l, int r, int val)
{
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (A[m] == val) {
            return m;
        } else if (A[m] < val) {
            l = m + 1;
        } else {
            r = m - 1;
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
