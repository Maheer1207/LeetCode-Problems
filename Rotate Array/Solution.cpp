#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int swap, n = nums.size();
        int middle = ceil(n/2)-1;
        
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
    }
};

int main() {
    
    Solution sol;
    int k = 3;
    vector<int> nums{1,2,3,4,5,6,7};
    
    sol.rotate(nums, k);
    
    return 0;
}
