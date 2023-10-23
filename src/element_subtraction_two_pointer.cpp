// Given a sorted array, Check whether it is possible to get Ai - Aj = k
// Solve using two pointers approach
#include <iostream>
using namespace std;

bool isPossible(int A[], int n, int k)
{
    int i = 0, j = 1;
    while (j < n) {
        int subtraction = A[j] - A[i];
        if (subtraction == k) {
            return true;
        } else if (subtraction < k) {
            j++;
        } else {
            i++;
            if (i==j) {
                j++;
            } 
        }
    }
    return false;
}

int main()
{
    int A[] = {1, 2, 4, 5, 10, 11};
    int n = sizeof(A)/sizeof(A[0]);
    int k = 8;

    if (isPossible(A, n, k)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}