// Program to find factorial of a number using recursion
#include <iostream>
using namespace std;

int findFactorial(int x)
{
    if (x == 1 || x == 0) {
        return 1;
    }

    return x*findFactorial(x-1);
}

int main()
{
    int x = 4;
    cout << "Factorial of a number is: " << findFactorial(x);
    return 0;
}