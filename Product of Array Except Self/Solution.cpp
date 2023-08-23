#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        
        for (int i=n-1; i>=0; i--) {
            if (i==n-1) {
                ans[i] *= nums[i];
            }
            else {
                ans[i] = nums[i]*ans[i+1];
            }
        }
        
        int pref = 1;
        for (int i=0; i<=n-1; i++) {
            if(i == n-1) {
                ans[i] = pref;
            }
            else{
                ans[i] = ans[i+1]*pref;
                pref *= nums[i];
            }
        }
        
        return ans;
    }
};

int main() {
    
    Solution sol;
    vector<int> nums{-1,1,0,-3,3};
    //vector<int> nums{1,2,3,4};
    
    vector<int> ans = sol.productExceptSelf(nums);
    
    
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
