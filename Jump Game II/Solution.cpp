//Question: https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canJump(vector<int>& jumps) {
        bool willJump = false;
        int start, end, jump, cnt = 0, curr = 0;
        int size = jumps.size()-1;
        
        while(curr <= size) {
            if (curr + jumps[curr] >= size) { 
                if (size > 0){ cnt++; }
                return cnt; 
            }
            
            jump = 0;
            start = curr+1;
            end = curr + jumps[curr];
            for (int i=start; i<=end; i++) {
                if(curr+jumps[curr]<i+jumps[i]){
                    jump = jumps[i];
                    curr = i;
                    willJump = true;
                }
            }
            
            if (willJump) { 
                cnt++; 
                willJump = false;
            }
        }
    }
};


int main()
{
    Solution sol;
    vector<int>jumps{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    
    cout << sol.canJump(jumps) << endl;
    
    return 0;
}
