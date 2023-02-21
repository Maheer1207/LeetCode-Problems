// Question: https://leetcode.com/problems/number-of-1-bits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        uint32_t andOp, shiftV, mult = 1;
        for (int i = 32; i > 0; i--) {
            andOp = n & mult;
            shiftV = andOp >> (32-i);
            mult = mult << 1;

            if (shiftV == 1) { cnt++; }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    uint32_t n;
    
    cin >> n;
    
    cout << sol.hammingWeight(n) << endl;

    return 0;
}
