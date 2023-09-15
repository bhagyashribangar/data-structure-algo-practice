#include <iostream>
#include <vector>
using namespace std;

bool checkPossibility(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            if (i - 2 >= 0 && nums[i] < nums[i - 2]) {
                nums[i] = nums[i - 1];
            } else {
                nums[i - 1] = nums[i];
            }
            count++;

            if (count > 1)
                return false;
        }
    }
    return true;
}

int main()
{
    vector<int> nums{4,2,3};
	cout << boolalpha << "Output is: " << checkPossibility(nums) << endl;
	return 0;
}