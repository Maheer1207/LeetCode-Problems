// Question: https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    void backtrack(vector<string> &answer, string cStr, int open, int close, int max) {
        if (cStr.length() == max*2) {
            answer.push_back(cStr);
            return;
        }
    
        if (open < max) { backtrack(answer, cStr+"(", open+1, close, max);}
        if (close < open) { backtrack(answer, cStr+")", open, close+1, max);}
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        
        if (n==0) {
            return answer;
        }
        
        backtrack(answer, "", 0, 0, n);
        return answer;
    }
    
};


int main() {
    Solution sol;
    vector<string> result;
    
    result = sol.generateParenthesis(3);
    
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}
