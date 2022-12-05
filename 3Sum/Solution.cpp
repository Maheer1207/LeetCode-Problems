//Question: https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
using namespace std;
 
 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> answers;

        sort(nums.begin(), nums.end());
    
        if(nums.size() < 3){ return {}; }

        if(nums[0] > 0 || nums[nums.size()-1] < 0){ return {}; }

        for (int x = 0; x < nums.size(); x++) {

            if(nums[x] > 0){ break; }

            if(x > 0 && nums[x] == nums[x - 1]){ continue; }

            int y = x+1, z = nums.size()-1;

            while(y < z) {

                if ((nums[x]+nums[y]+nums[z]) > 0 ) {
                    z--;
                }
                else if ((nums[x]+nums[y]+nums[z]) < 0) {
                    y++;
                }
                else {
                    int val2 = nums[y], val3 = nums[z];
                    answers.push_back({nums[x], nums[y], nums[z]});

                    while (nums[y] == val2 && y < z) {
                        y++;
                    }

                    while (nums[z] == val3 && y < z) {
                        z--;
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
   vector <int> nums{-1,0,1,2,-1,-4};
   vector<vector<int>> answers;
   answers = sol.threeSum(nums);
    
    for (auto i: answers) {
        for (auto j: i){
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}
