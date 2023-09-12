/* Leet code 209: Minimum size subarray sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.*/

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int n, int m, int target, int* prefixSum)
{
    int sum = 0;
    for (int i = m - 1; i < n; ++i) {
        int k = i - m;
        if (k >= 0) {
            sum = prefixSum[i] - prefixSum[k];
        } else {
            sum = prefixSum[i];
        }
        if (sum >= target) {
            return true;
        }
    }
    return false;
}

int minSubArrayLen(int target, vector<int>& nums) 
{
    int n = nums.size();
    int* prefixSum = new int[n];
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    int result = 0;
    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (isPossible(n, mid, target, prefixSum)) {
            if (result > 0) {
                result = std::min(mid, result);
            } else {
                result = mid;
            }
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return result;
}

int main()
{
    vector<int> A{2,3,1,2,4,3};
    int target = 7;

	cout << "Size of subarray is: " << minSubArrayLen(target, A) << endl;
	return 0;
}