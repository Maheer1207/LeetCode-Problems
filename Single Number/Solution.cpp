// Question: https://leetcode.com/problems/single-number/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i<nums.size(); i++) {
            result ^= nums[i];  // XOR opertation
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums {2,2,1,3,1,4,4};
    
    cout << sol.singleNumber(nums) << endl;

    return 0;
}
