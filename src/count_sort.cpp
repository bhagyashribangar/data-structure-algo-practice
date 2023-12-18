// Implementation of count sort

#include <iostream>
#include <vector>
using namespace std;

vector<int> countSort(vector<int>& inputArray) {
	int N = inputArray.size();
	int M = 0;

	for (int i = 0; i < N; i++) {
        M = max(M, inputArray[i]);
    }

	// Initialize countArray[] with 0
	vector<int> countArray(M + 1, 0);

	// Mapping each element of inputArray[] as an index of countArray[] array
	for (int i = 0; i < N; i++) {
        countArray[inputArray[i]]++;
    }

	// Calculating prefix sum
	for (int i = 1; i <= M; i++) {
        countArray[i] += countArray[i - 1];
    }

	// Creating outputArray[] from countArray[] array
	vector<int> outputArray(N);

	for (int i = N - 1; i >= 0; i--) {
		outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
		countArray[inputArray[i]]--;
	}

	return outputArray;
}

int main()
{
	vector<int> inputArray = {4, 3, 12, 1, 5, 5, 3, 9};

	vector<int> outputArray = countSort(inputArray);

	for (int i = 0; i < inputArray.size(); i++) {
        cout << outputArray[i] << " ";
    }

	return 0;
}
