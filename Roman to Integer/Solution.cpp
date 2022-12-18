//Question: https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:int romanToInt(string s) {
            int num = 0;
        
        unordered_map<char, int>New_map = {{'I', 1}, 
                                          {'V', 5},
                                          {'X', 10}, 
                                          {'L', 50},
                                          {'C', 100},
                                          {'D', 500},
                                          {'M', 1000}};
        int sum = New_map[s.back()];
        for (int i = s.length()-2; i >= 0; i--) {
            if (New_map[s[i]] < New_map[s[i + 1]]) {
                sum -= New_map[s[i]];
            }
            else {
                sum += New_map[s[i]];
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    string romanNum;
    cin >> romanNum;
    cout << s.romanToInt(romanNum) << endl;
}
