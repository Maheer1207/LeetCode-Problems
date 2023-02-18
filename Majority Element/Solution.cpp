// Question: https://leetcode.com/problems/majority-element/description/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      unordered_map<int, int> hmap;
      
      for (int i = 0; i < nums.size(); i++) {
          hmap[nums[i]]++;
      }

      int val=0, maj = 0;
      for (auto ele: hmap) {
          if ((maj < ele.second) && (ele.second > floor(nums.size()/2))){
              maj = ele.second;
              val = ele.first;
          }
      }
      return val;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums {2,2,1,1,1,2,2};
    
    cout << sol.majorityElement(nums) << endl;

    return 0;
}
