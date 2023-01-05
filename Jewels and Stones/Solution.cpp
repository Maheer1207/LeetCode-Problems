//Question: https://leetcode.com/problems/jewels-and-stones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> map;
        int cnt = 0;
        for (auto s: stones) {
            map[s]++;
        }
        for (auto j:jewels) {
            cnt += map[j];
        }
        return cnt;
    }
};


int main() {
    string jewels, stones;
    cin >> jewels >> stones;
    Solution s;
    cout << s.numJewelsInStones(jewels, stones) << endl;
}
