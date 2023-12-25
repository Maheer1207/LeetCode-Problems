#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> hmap;
        vector<int> list;
        
        if (nums.size()<1) {return 0;}
        for (int i=0; i<nums.size(); i++) { hmap[nums[i]]++; }

        auto itr_first = hmap.begin();
        int cnt = 1, curr = itr_first->first;
        itr_first++;
        
        for (auto i=itr_first; i!=hmap.end(); i++) {
            if (i->first - curr == 1) { 
                cnt++;
                curr = i->first;
            }
            else {
                list.push_back(cnt);
                cnt = 1;
                curr = i->first;
            }
        }
        list.push_back(cnt);
        
        int lng = 0;
        for (int i=0; i<list.size(); i++) {
            if (list[i]>lng) lng = list[i];
        }

        return lng;
    }
};

int main()
{
    Solution sol;
    
    // vector<int> nums{100,4,200,1,3,2};
    vector<int> nums{9,1,4,7,3,-1,0,5,8,-1,6};
    cout << sol.longestConsecutive(nums) << endl;
    
    return 0;
}
