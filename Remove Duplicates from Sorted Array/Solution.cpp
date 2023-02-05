//Question: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int swap;

        for (int j =1; j<nums.size(); j++) {
            if (nums[i] != nums[j]) {
                swap = nums[j];
                nums[j] = nums[i+1];
                nums[i+1] = swap;
                i++;
            }
        }

        return i+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums{1,1,2};
    vector<int> expNums{1,2};
    
    int k = sol.removeDuplicates(nums);

    for (int i = 0; i < k; i++) {
        cout << "Actual: " << nums[i] << "|| Expected: " << expNums[i] << endl;
    }
    
    return 0;
}
