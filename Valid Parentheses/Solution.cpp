// Question: https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> parenthesis = {{'(', 1},
        {'[', 2},
        {'{', 3},
        {')', -1},
        {']', -2},
        {'}', -3}};
    
        stack<int> stackP;
    
        for (auto p: s) {
            if (parenthesis[p] > 0) {
                stackP.push(p);
            }
            else if (!stackP.empty()) {
                if (parenthesis[stackP.top()] != (-1*parenthesis[p])) {
                    return false;
                }   
                stackP.pop();
            }
            else { return false; }
        }
    
        if (stackP.empty()) {
            return true;
        }
    
        return false;
    }
};

int main() {
    Solution sol;
    
    // "()[]{}"
    // "(]"
    string s;
    cin >> s;
    
    cout << sol.isValid(s) << endl;
    
    cout << endl;

    return 0;
}
