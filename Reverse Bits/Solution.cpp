// Question: https://leetcode.com/problems/reverse-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t andF, andB, result = 0, multB = 1, multF = 2147483648;
        for (int i = 0, j = 32; i < 16, j > 16; i ++, j--) {
            andF = n & multF;
            andB = n & multB;
            result = result | (andF >> (31-(i*2))) | (andB << (31-(i*2)));
            multF = multF >> 1;
            multB = multB << 1;
        }
        return result;
    }
};

int main() {
    Solution sol;
    uint32_t n;
    
    cin >> n;
    
    cout << sol.reverseBits(n) << endl;

    return 0;
}
