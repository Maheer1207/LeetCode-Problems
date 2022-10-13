#Question: https://leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>
using namespace std;

class LongestPalindrome {
    
    public:string findLongestPalindrome(string s) {
        int start, end, max = -1;
        string palindrom = "";
        int dp[s.length()][s.length()];
        memset(dp, 0, sizeof dp); 

        for (int i = 0; i<=s.length()-1; i++) {
            for (int j=0, y=i; y<=s.length()-1; j++, y++) {
                if (j == y) { dp[j][y] = 1;}
                else if (y-j == 1 && s[j] == s[y]) {dp[j][y] = 1;}
                else if (s[j] == s[y]) {dp[j][y] = dp[j+1][y-1];}
                else {dp[j][y] = 0;}
            }
        }

        for (int i = 0; i<=s.length()-1; i++) {
            for (int j=0, y=i; y<=s.length()-1; j++, y++) {
                if (dp[j][y] == 1 && (y-j)>max) {
                    max = y-j;
                    start = j;
                    end = y;
                }
            }
        }

        for (int i = start; i<=end; i++) {
            palindrom += s[i];
        }
        return palindrom;
    }
};


int main() {
    LongestPalindrome lp;
    string s;
    cin >> s;
    cout << lp.findLongestPalindrome(s);
}
