//Question: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int m, l = 0, r = nums.size()-1;
        while(l <= r){
            m = (l+r)/2;
            if(nums[m] == target) return m;
            if(nums[m] >= nums[l]) {
                if(target >= nums[l] && target <= nums[m]) r = m - 1;
                else l = m + 1;
            } 
            else {
                if(target >= nums[m] && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
            m = l + (r - l) / 2;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int target = 0;
    vector<int> nums {4,5,6,7,0,1,2};
    
    cout << sol.search(nums, target) << endl;
    
    cout << endl;

    return 0;
}
