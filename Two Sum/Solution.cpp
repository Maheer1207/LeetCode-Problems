// Question: https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        int index;
        map<int,int>mymap;
        map<int,int>::iterator it;
        vector<int>ans;
        for(index=0;index<nums.size();index++){
            it=mymap.find(target-nums[index]);
                if(it!=mymap.end()){
                     ans.push_back(it->second);
                     ans.push_back(index);
                    break;
                }
            else{
                mymap.insert(make_pair(nums[index],index));
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{3,3};
    int target = 6;
    //cin >> romanNum;
    vector<int> result = s.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
            cout << result[i]<<endl;
        }
}
