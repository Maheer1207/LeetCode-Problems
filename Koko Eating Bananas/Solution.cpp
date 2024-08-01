//Question: https://leetcode.com/problems/koko-eating-bananas/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort(piles.begin(), piles.end());
        int cnt, m, l=1, r = piles[piles.size()-1];
        
        while (l<r) {
            cnt = 0;
            m = (l+r)/2;
            
            for (int i=0; i<piles.size(); i++) {
                cnt += piles[i]/m;
                if (piles[i]%m != 0) { cnt++; }
            }
            
            if (cnt <= h) { r = m; }
            else { l = m+1; }
        }
        
        return l;
    }
};

int main() {
    Solution sol;
    int h = 8;
    vector<int> piles {3,6,7,11};
    
    cout << sol.minEatingSpeed(piles, h) << endl;
    
    cout << endl;

    return 0;
}
