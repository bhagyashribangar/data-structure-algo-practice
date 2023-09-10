// Assign hooks to the cows such that the minimum distance is maximum
// n = hooks or size of array, c = number of cows
// return maximum possible minimum distance
// TC:  O(Nlog(M)); M = A[n-1] - A[0], SC: O(1)
// This solution is applicable for sorted input array

#include <iostream>
#include <limits.h>
using namespace std;

bool isPossible(int A[], int m, int n, int c)
{
    int count = 1;
    int dist = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] - A[dist] >= m) {
            dist = i;
            count++;
        }
        if (count >= c) {
            return true;
        }
    }

    return false;
}

int findMaxDistance(int A[], int n, int c)
{
    int l = 0, r = A[n-1] - A[0];
    int result = -1;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (isPossible(A, m, n, c)) {
                result = m;
                l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return result;
}

int main()
{
    int A[] = {4, 11, 18, 24, 28, 32};
    int n = sizeof(A)/sizeof(A[0]);
    int c = 3;

    cout << "Maximum distance is: " << findMaxDistance(A, n, c);
    return 0;
}