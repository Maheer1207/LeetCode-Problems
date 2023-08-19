//Question: https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hInd = 0, cnt = 0, n = citations.size();
        
        for (int i=n-1; i>=0; i--) {
            cnt = 0;
            for (int j=0; j<n; j++){
                if(citations[j] >= i+1) { cnt++; }
            }
            if(cnt >= i+1) {
                hInd = i+1;
                break;
            }
        }
        
        return hInd;
    }
};


int main()
{
    Solution sol;
    vector<int>citations{1,3,1};
    
    cout << sol.hIndex(citations) << endl;
    
    return 0;
}
