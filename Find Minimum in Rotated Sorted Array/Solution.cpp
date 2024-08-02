// Question: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int m, l = 0, r = nums.size()-1, res=nums[0];
        while(l <= r){
            if (nums[l]<nums[r]) {
                res = min(res, nums[l]);
                break;
            }
            
            m = (l+r)/2;
            res = min(res, nums[r]);
            if(nums[m] >= nums[l]) { l = m + 1; } 
            else { r = m - 1; }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums {3,4,5,1,2};
    
    cout << sol.findMin(nums) << endl;

    return 0;
}
