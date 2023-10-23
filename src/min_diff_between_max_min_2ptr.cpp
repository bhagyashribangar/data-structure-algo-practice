// Tuple with difference between max and min is minimum
// Given 3 sorted arrays of positive integers, for tuple (Ai, Bi, Ci)
// find the index at which "max(A,B,C) - min(A,B,C)" is minimum
// 3 pointer approach

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> findIndex(vector<int>& A, vector<int>& B, vector<int>& C)
{
    int i = 0, j = 0, k = 0; 
    int min_diff = INT_MAX;
    vector<int> result;

    while ( i < A.size() && j < B.size() && k < C.size()) {
        int maxVal = max(max(A[i],B[j]),C[k]);
        int minVal = min(min(A[i], B[j]), C[k]);
        int diff =  maxVal - minVal;
        if (diff == 0) {
            // Added this condition to find first occurance of indices of min diff
            result = {i, j, k};
            break;
        } else if (diff < min_diff) {
            min_diff = diff;
            result = {i, j, k};
        }

        if (minVal == A[i]) {
            i++;
        } else if (minVal == B[j]) {
            j++;
        } else {
            k++;
        }

    }

    return result;
}

int main()
{
    vector<int> A{2, 4, 5, 6, 8, 12};
    vector<int> B{5, 6, 8, 10};
    vector<int> C{3, 6, 12};

    vector<int> result = findIndex(A, B, C);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " "; 
    }

    return 0;
}