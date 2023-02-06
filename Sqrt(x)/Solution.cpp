//Question: https://leetcode.com/problems/sqrtx/description/

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        long i = 1;
        long sq = i * i;
        while (x >= sq) {
            i++;
            sq = i * i;
        }
        return (int) (i - 1);
    }
};

int main() {
    Solution sol;
    int nums;
    cin >> nums;
    
    cout << sol.mySqrt(nums) << " " << endl;
    
    return 0;
}
