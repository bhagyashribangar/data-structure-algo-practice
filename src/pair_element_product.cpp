// Count total number of combinations such that a*b <= k

#include <iostream>
#include <vector>
using namespace std;

int countCombinations(vector<int>& A, int k)
{
    int i = 0, j = A.size() - 1;
    int count = 0;
    while (i < j) {
        int product = A[i] * A[j];
        if (product > k) {
            j--;
        } else if (product <= k) {
            // here we are adding 1 because we need to count pair (a*a or b*b as well)
            count += (j - i + 1);
            i++;
        }
    }
    return count;
}

int main()
{
    vector<int> A{2, 3, 4, 5, 7};
    int k = 14;

    cout << "Number of possible combinations are: " << countCombinations(A, k);

    return 0;
}