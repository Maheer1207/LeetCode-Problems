#Question: https://leetcode.com/problems/reverse-string-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        if (k>s.size()) {
            reverse(s.begin(), s.end());
        }
        else {
            for (int i=0; i<s.size(); i=i+k) {
                if((i/k)==0 || ((i/k)%2)==0) {
                    int end = ((k*((i/k)+1))-1)<s.size() ? (k*((i/k)+1))-1 : s.size()-1;
                    reverse(s.begin()+i, s.begin()+end+1);
                }
            }
        }
        
        return s;
    }
};

int main() {
    Solution sol;
    string s;
    int x;
    cin >> s;
    cin >> x;
    cout << sol.reverseStr(s, x) << endl;
}
