// Maxmum value of absolute function
#include <iostream>
using namespace std;
#define MAX 10

// Return maximum value of |arr[i] - arr[j]| + |i - j|
int findMaxValue(int arr[], int n)
{
	int ans = 0;

	// Iterating two for loop, one for
	// i and another for j.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			// Evaluating |arr[i] - arr[j]| + |i - j|
			// and compare with previous maximum.
			ans = max(ans, abs(arr[i] - arr[j]) + abs(i - j));
	return ans;
}

// Driven Program
int main()
{
	int arr[] = { 1, 2, 3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << findMaxValue(arr, n) << endl;

	return 0;
}
