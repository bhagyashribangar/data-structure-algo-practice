// Fill given numbers 0,1 in array of size 4 using backtracking
#include <iostream>
#include <vector>
using namespace std;

void fillArray(vector<int>& arr, int index, int size) {
    if (index == size) {
        // Print the array if it is filled completely
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    // Try filling the current index with 0 and 1
    for (int value = 0; value <= 1; value++) {
        arr[index] = value;
        fillArray(arr, index + 1, size);
    }

    /*arr[index] = 0;
    fillArray(arr, index + 1, size);
    arr[index] = 1;
    fillArray(arr, index + 1, size);*/
}

int main() {
    int size = 4;
    vector<int> arr(size);

    cout << "All possible arrays of size " << size << " with 0s and 1s:" << endl;
    fillArray(arr, 0, size);

    return 0;
}
