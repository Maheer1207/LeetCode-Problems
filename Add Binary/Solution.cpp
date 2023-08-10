#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string large, small, result = "";

        if (a.length() >= b.length()) { 
            large = a; 
            small = b;
        }
        else { large = b; small = a;}

        bool overflow = false;
        int largeInd = large.length()-1;
        int smallInd = small.length()-1;

        while (largeInd >= 0) {
            if (smallInd >= 0) {
                if (large[largeInd] == '0' && small[smallInd] == '0') {
                    if (overflow) { result = '1' + result; }
                    else { result = '0' + result; }
                    overflow = false;
                }
                else if (large[largeInd] == '1' && small[smallInd] == '1') {
                    if (overflow) { result = '1' + result; }
                    else { result = '0' + result; }
                    overflow = true;
                }
                else {
                    if (overflow) { 
                        result = '0' + result;
                    }
                    else { 
                        result = '1' + result;
                    }
                }
            }
            else {
                if (large[largeInd] == '0') {
                    if (overflow) { result = '1' + result; }
                    else { result = '0' + result; }
                    overflow = false;
                }
                else {
                    if (overflow) { result = '0' + result; }
                    else { result = '1' + result; }
                }
            }
            
            largeInd--;
            smallInd--;
        }

        if (overflow) { result = '1' + result; }

        return result;
    }
};
 
int main() {
   Solution sol;
   string a = "1010";
   string b = "1011";
   string k = sol.addBinary(a, b);
   
   cout << k << endl;
   return 0;
}
