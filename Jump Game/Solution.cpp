//Question: https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& jumps) {
        int reachable = 0;
        
        for(int i=0; i<jumps.size(); i++) {
            if(reachable < i) { return false; }
            
            reachable = max(reachable, i+jumps[i]);
        }
        
        return true;
    }
};


int main()
{
    Solution sol;
    vector<int>jumps{2,3,1,1,4};
    //vector<int>jumps{3,2,1,0,4};
    
    cout << sol.canJump(jumps) << endl;
    
    return 0;
}
