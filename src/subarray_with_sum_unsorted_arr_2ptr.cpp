// Given an Unsorted array find number of subarrays whose sum is k
// SOlve using 2 pointer

#include <iostream>
#include <vector>
using namespace std;

void findSubarrays(vector<int>& A, int k)
{
    int i = 0, j = 1;
    while (i < j) {
        int sum = 0;
        for (int a = i; a<=j; a++) {
            sum += A[a];
        }
        if (sum == k) {
            cout << "subarray with addition equal to given number found at index i = " << i << ", j = " << j;
            return;
        } else if (sum < k) {
            j++;
        } else {
            i++;
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