// Given an integer A representing the number of square blocks
// The task is to create a staircase of max-height using the given blocks,
// 1st step will need 1 block, next will need 2 blocks and so on..
// Find maximum height of the stairecase that can be made using given square blocks
#include<iostream>
using namespace std;

int FindMaxHtofStaircase(int A)
{
    int l = 1, r = A, height = 1;
    while(l <= r){
        int m = l + (r-l)/2;
        if ((m * (m+1))/2 <= A) {
            l = m + 1;
            height = m;
        } else {
            r = m - 1;
        }
    }
    return height;
}

int main()
{
    int A = 15;
    cout << "Maximum height of staircase using given blocks: " << A << ", is: " << FindMaxHtofStaircase(A);
    return 0;
}
