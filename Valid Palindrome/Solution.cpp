// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        for (auto c: s) {
            if (c>=65 && c<=90) { newS += tolower(c); }
            else if (c>=97 && c<=122) { newS += c; }
        }
        
        cout << newS << " " << newS.length()<< endl;

        if (newS.length() == 0) { return true; }
        if (newS.length() == 1) { return false; }
        
        int i = 0, j = newS.length()-1;

        while ((j-i)>1) {
            if (newS[i] != newS[j]) { return false;}
            i++;
            j--;
            cout << i << ":" << j << endl;
        }

        if (((newS.length())%2 == 0) && (newS[i] != newS[j])) { return false; }

        return true;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.isPalindrome(s) << endl;

    return 0;
}
