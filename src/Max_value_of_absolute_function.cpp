// Maximum value of absolute function
#include <iostream>
using namespace std;

// Return maximum value of |arr[i] - arr[j]| + |i - j|
int findMaxValue(int arr[], int n)
{
	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			// Evaluating |arr[i] - arr[j]| + |i - j|
			// and compare with previous maximum.
			ans = max(ans, abs(arr[i] - arr[j]) + abs(i - j));
	return ans;
}

int main()
{
	int arr[] = {2, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << findMaxValue(arr, n) << endl;

	return 0;
}
