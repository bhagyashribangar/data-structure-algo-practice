// Find square root of a number A
// DO not use standard library function to find square root
// TC: O(log(A)), SC: O(1)

#include<iostream>
using namespace std;

int findSquareRoot(int A)
{
    int l=1, r=A/2, sqroot;
    while(l<=r) {
        int mid = (l+r)/2;
        int square = mid * mid;
        if (square == A) {
            return mid;
        } else if (square <= A) {
            l = mid + 1;
            sqroot = mid;
        } else {
            r = mid - 1;
        }
    }
    return sqroot;
}

int main()
{
    int A = 18;
    cout << "Square root of a given number: " << A << " is: " << findSquareRoot(A);
    return 0;
}