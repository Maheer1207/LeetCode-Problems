//Question: https://leetcode.com/problems/length-of-last-word/description

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length()-1;
        int count = 0;

        while (s[index] == ' ' && index >= 0) { index--; }

        while (s[index] != ' ' && index >= 0) {
            count++;
            index--;
        }

        return count;
    }
};
 
int main() {
   Solution sol;
   string s = "a";
   int k = sol.lengthOfLastWord(s);
   
   cout << k << endl;
   return 0;
}
