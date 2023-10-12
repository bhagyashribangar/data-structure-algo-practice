// Backtracking problem
// Given an integer array A of size n, and integer B 
// Find and return non-empty subsequence of A of size B having sum <= 1000
#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
void countSubsequences(vector<int>& A, int B, int target, int currSum, int currentIndex, int currSize) {

    if (currSize == B && currSum <= target) {
        cnt++;
        return;
    }

    if (currSize > B || currSum > target) {
        return;
    }

    for (int i = currentIndex; i < A.size(); ++i) {
        countSubsequences(A, B, target,  currSum + A[i], i + 1, currSize + 1);
    }
}

int main() {
    int B = 2, X = 1000;
    vector<int> A {1, 2, 8};

    countSubsequences(A, B, X, 0, 0, 0);
    cout << "Number of non-empty subsequences of size " << B << " with sum less than " << X << ": " << cnt << endl;

    return 0;
}
