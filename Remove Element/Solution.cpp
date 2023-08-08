//Question: https://leetcode.com/problems/remove-element

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int i = 0;

      for (int j=0; j<nums.size(); j++){
        if (nums[j] != val) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
      }
      return i;
    }
};
 
int main() {
   Solution sol;
   vector <int> nums{0,1,2,2,3,0,4,2};
   int val = 4;
   //cin >> val;
   int k = sol.removeElement(nums, val);
   
   cout << k << endl;
   return 0;
}
