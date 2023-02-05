//Question: https://leetcode.com/problems/plus-one/description/

#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {    
        vector<int> result;
        if (digits[digits.size()-1] == 9) {
            int p = digits.size()-1;
            int h=0, value=0;

            value = digits[p]+1;
            h = value/10;
            result.push_back(value%10);
            p--;

            while (p >= 0) {
                value = digits[p]+h;
                h = value / 10;
                result.push_back(value%10);
                p--;
            }

            if (h>0) {
                result.push_back(h);
            }

            reverse(result.begin(), result.end());
            return result;
        }
        
        digits[digits.size()-1] += 1;
        return digits;
    }
};

int main() {
    Solution sol;
    vector<int> nums{5,2,2,6,5,7,1,9,0,3,8,6,8,6,5,2,1,8,7,9,8,3,8,4,7,2,5,8,9};
    vector<int> res;
    
    res = sol.plusOne(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " " << endl;
    }
    
    return 0;
}
