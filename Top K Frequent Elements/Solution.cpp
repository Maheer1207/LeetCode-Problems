#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> hmap;
        
        for (int i=0; i<nums.size(); i++) {
            hmap[nums[i]]++;
        }
        
        int cmpr_key, cmpr_val;
        for (int i=0; i<k; i++) {
            cmpr_val = 0;
            for (auto ele:hmap) {
                if (cmpr_val < ele.second) {
                   cmpr_key = ele.first;
                   cmpr_val = ele.second; 
                }
            }
            result.push_back(cmpr_key);
            hmap.erase(cmpr_key);
        }
        
        return result;
    }
};

int main()
{
   Solution sol;
   vector <int> nums{1,1,1,2,2,3};
   int k = 2;
   
   vector<int> res;
   
   res = sol.topKFrequent(nums, k);
   
   for(int i=0; i<res.size(); i++){
       cout << res[i] << endl;
   }            
   
   return 0;
}
