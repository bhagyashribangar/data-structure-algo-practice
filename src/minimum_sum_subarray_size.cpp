// Given an array of integers A and an integer/sum B, 
// find and return the maximum value K such that 
// there is no subarray in A of size K with the sum of elements greater than B.
#include <iostream>
using namespace std;

bool isPossible(int A[], int N, int k, int B)
{
    int sum = 0;   
    int prefixSum[5];
    prefixSum[0] = A[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }
    for (int i = (k - 1); i < N; ++i) {
        if ((i-k) >= 0) {
            sum = prefixSum[i] - prefixSum[i - k];
        } else {
            sum = prefixSum[i];
        }
    }
    if (sum > B) {
        return false;
    } else {
        return true;
    }
}

int minSumSubArray(int A[], int N, int B)
{
    int result = 0;
    int l = 1, r = N;
    while (l <= r) {
        int k = (l+r)/2;
        if (isPossible(A, N, k, B)) {
            result = k;
            l = k+1;
        } else {
            r = k-1;
        }
    }
    return result;
}

int main()
{
    int A[] = {5, 17, 100, 11};
	int n = sizeof(A) / sizeof(A[0]);
    int B = 130;

	cout << "Size of subarray is: " << minSumSubArray(A, n, B) << endl;
	return 0;
}