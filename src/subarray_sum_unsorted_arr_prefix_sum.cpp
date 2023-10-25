// Given an Unsorted array find number of subarrays whose sum is k 
// Solve using prefix sum array

#include <iostream>
#include <vector>
using namespace std;

void findSubarrays(vector<int>& A, int k)
{
    int n = A.size();
    int prefixSum[6];
    prefixSum[0] = A[0];
    for (int x = 1; x < n; x++) {
        prefixSum[x] = prefixSum[x-1] + A[x];
    }

    int i = 0, j = 1;
    while (j < n) {
        int subtraction = prefixSum[j] - prefixSum[i];
        if (subtraction == k) {
            cout << "subarray with addition equal to given number found at index i = " << i+1 << ", j = " << j;
            return;
        } else if (subtraction < k) {
            j++;
        } else {
            i++;
            if (i==j) {
                j++;
            } 
        }
    }
}

int main()
{
    vector<int> A{2, 4, 3, 6, 5, 10};
    int k = 14;

    findSubarrays(A, k);

    return 0;
}