// Find value of i and j for maximum value of absolute funtion
#include <iostream>
#include <limits.h>
using namespace std;

// time complexity = O(n^2) 
void findIndex(int A[], int n)
{
    int result = 0, max_i = 0, max_j = 0;
    for(int i = 0; i <n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int max1 = abs(A[i]-A[j]) + abs(i-j);
            if (max1 > result) {
                result = max1;
                max_i = i; 
                max_j = j;
            }
        }
    }
    cout << "Max value of i is: " << max_i << " and j is: " << max_j << "\n";
}

int main()
{
    int A[] = {3, -2, 6, 0};
    int n = sizeof(A)/sizeof(A[0]);
    findIndex(A, n);
    return 0;
}
