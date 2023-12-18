// Maximum difference between group of k-elements and rest of the array
// Find the maximum difference between sum
// max(sum(k) - sum(n-k))

#include<iostream>
#include <algorithm>
using namespace std;

int maxDiff(int A[], int N, int k) {
    if (k > N) {
        return -1;
    }
    sort(A, A+N);
    
    int lSum = 0;
    for (int i = 0; i < k; ++i) {
        lSum += A[i];
    }

    int rSum = 0;
    for (int i = k; i < N; ++i) {
        rSum += A[i];
    }

    int result = 0;
    if (rSum > lSum) {
        result = rSum - lSum;
    } else {
        result = lSum - rSum;
    }
    return result;
}

int main() {
    int A[] = {1, 7, 4, 8, -1, 5, 2, 1};
    int N = sizeof(A)/sizeof(A[0]);
    int k = 3;
    cout << "Max difference is: " << maxDiff(A, N, k) << endl;

    return 0;
}
