// Find rotation point of sorted circular array
/* In a sorted circular array, a "rotation point" or "pivot" is the index where 
the array's elements transition from being in ascending order to a different order due to rotation. 
The rotation point is the index of the smallest element in the array */

#include <iostream>
#include <vector>
using namespace std;

int findRotationPoint(const std::vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if the mid element is greater than the rightmost element
        if (arr[mid] > arr[right]) {
            left = mid + 1; // Move the left boundary to the right of mid
        } else {
            right = mid; // Move the right boundary to mid (or left of it)
        }
    }

    return left; // The left boundary will point to the rotation point
}

int main() {
    vector<int> arr = {5, 1, 2, 3, 4};
    int rotationPoint = findRotationPoint(arr);

    cout << "The rotation point is at index " << rotationPoint << endl;
    cout << "The smallest element is " << arr[rotationPoint] << endl;

    return 0;
}
