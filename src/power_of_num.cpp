// Program to find a power of a given number
#include <iostream>
#include <algorithm>
using namespace std;

int numPower(int n, int p)
{
    int result = 1;
    //return pow(n, p); // pow requires input args as double or typecast it
    for (int i = 0; i < p; ++i) {
        result *= n;
    }

    return result;
}

int main()
{
    int n = 2;
    int p = 3;

    cout << "Power of a given number is: " << numPower(n, p);
    return 0;
}