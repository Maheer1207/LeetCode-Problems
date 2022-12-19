// Question: https://leetcode.com/problems/number-of-good-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> hash;
        int cnt = 0;
        for(auto n:nums)
        {
           cnt += hash[n]++;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,2,3,1,1,3};
    cout << s.numIdenticalPairs(nums) << endl;
}
