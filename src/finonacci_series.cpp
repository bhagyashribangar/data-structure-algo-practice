// Program to find finonacci series up to a specified number
#include <iostream>
using namespace std;

int fiboSeries(int x)
{
    if (x <= 1) {
        return x;
    }
    return fiboSeries(x-1) + fiboSeries(x-2);
}

int main()
{
    int x = 5;
    cout << "Fibonacci series for given number is: " << fiboSeries(x);
    return 0;
}