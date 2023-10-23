// Given a sorted array, Check whether it is possible to get Ai + Aj = k
// Solve using two pointers approach
#include <iostream>
using namespace std;

bool isPossible(int A[], int n, int k)
{
    int i = 0, j = n-1;
    while (i < j) {
        int sum = A[i] + A[j];
        if (sum == k) {
            return true;
        } else if (sum > k) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}

int main()
{
    int A[] = {1, 2, 4, 5, 10, 11};
    int n = sizeof(A)/sizeof(A[0]);
    int k = 13;

    if (isPossible(A, n, k)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}