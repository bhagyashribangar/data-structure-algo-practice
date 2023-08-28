// Given an array of integers A of size N and an integer B.
// The College library has N books. The ith book has A[i] number of pages.
// You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.
// Calculate and return that minimum possible number.
// NOTE: Return -1 if a valid assignment is not possible.
#include<iostream>
#include<algorithm>
#include <limits.h>
using namespace std;

bool isPossible(int A[], int N, int B, int mid)
{
    int students = 1;
    int curr_sum = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] > mid) {
            return false;
        }
        if (curr_sum + A[i] > mid) {
            students++;
            curr_sum = A[i];

            if (students > B) {
                return false;
            }   
        } else
            curr_sum += A[i];
    }
    return true;
}

int allocateBook(int A[], int N, int B)
{
    if (N < B) {
        return -1;
    }

    int sum = 0;
    int max1 = INT_MIN;
    for (int i=0; i<N; ++i) {
        sum += A[i];
        max1 = max(max1, A[i]);
    }
    int l = max1, r = sum;
    int result = INT_MAX;

    while (l<=r) {
        int mid = (l + r)/2;
        if (isPossible(A, N, B, mid)) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return result;
}

int main()
{
    int A[] = {12, 34, 67, 90};
    int B = 2;
    int N = sizeof(A)/sizeof(A[0]);
    cout << "minimum possible number of pages: " << allocateBook(A, N, B);
    return 0;
}