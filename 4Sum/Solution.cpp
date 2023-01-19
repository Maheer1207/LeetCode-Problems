// Question: https://leetcode.com/problems/4sum/description/

#include <bits/stdc++.h>
using namespace std;
 
 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> answers;

        sort(nums.begin(), nums.end());
    
        if(nums.size() < 4){ return {}; }

        for (int m=0; m < nums.size()-3; m++) {
            if(m > 0 && nums[m] == nums[m - 1]){ continue; }
            for (int x = m+1; x < nums.size()-2; x++) {
                if(x > m+1 && nums[x] == nums[x - 1]){ continue; }
                int y = x+1, z = nums.size()-1;
                while(y < z) {
                    long long sum = (long long) nums[m]+nums[x]+nums[y]+nums[z];
                    if (sum > target ) {
                        z--;
                    }
                    else if (sum < target) {
                        y++; 
                    }
                    else {
                        int val2 = nums[y], val3 = nums[z];
                        answers.push_back({nums[m], nums[x], nums[y], nums[z]});
                        while (nums[y] == val2 && y < z) {
                            y++;
                        }
                        while (nums[z] == val3 && y < z) {
                            z--; 
                        }
                    }
                }
            }
        }
        
        return answers;
    }
};
 
 
int main()
{
   Solution sol;
   vector <int> nums{-1000000000,-1000000000,1000000000,-1000000000,-1000000000};
   int target = 294967296;
   vector<vector<int>> answers;
   answers = sol.fourSum(nums, target);
    
    for (auto i: answers) {
        for (auto j: i){
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}
