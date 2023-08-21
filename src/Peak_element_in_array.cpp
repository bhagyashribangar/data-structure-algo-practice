/* Given an array of integers A, find and return the peak element in it.
An array element is considered a peak if it is not smaller than its neighbors. 
For corner elements, we need to consider only one neighbor.
NOTE: It is guaranteed that the array contains only a single peak element.
Users are expected to solve this in O(log(N)) time. The array may contain duplicate elements.*/
// TC: O(log(n)), SC: O(1)
#include<iostream>
using namespace std;

int peakElement(int A[], int l, int r)
{
    while (l<=r) {
        int m = l + (r-l)/2;
        if (A[m-1] > A[m]) {
            r = m-1;
        } else if (A[m+1] > A[m]) {
            l = m+1;
        } else {
            return A[m];
        }
    }

    return 0;
}

int main()
{
    int A[] = {1, 2, 3, 5, 7, 4};
	int n = sizeof(A) / sizeof(A[0]);

	cout << "Peak element in array is: " << peakElement(A, 0, n-1) << endl;
	return 0;
}