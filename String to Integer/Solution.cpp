#Question: https://leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
using namespace std;

class StringtoInteger {
    public:int myAtoi(string s) {
        bool firstDigit = false, firstPosDigit = false;
        int pos = 0, neg = 0, index = 0;
        string result = "0";
        
        while (index <s.length()) {
            if (s[index] >= '0' && s[index] <= '9'){
                if (!firstDigit){ firstDigit = true; }
                if (s[index] == '0' && firstPosDigit) {
                    result += s[index];
                }
                else if (s[index] != '0') {
                    result += s[index];
                    if (!firstPosDigit){ firstPosDigit = true; }
                }
            }
            else if (s[index] == '-' && !firstDigit) {neg++;}
            else if (s[index] == '+' && !firstDigit) {pos++;}
            else if (firstDigit || pos > 0 || neg > 0|| (!firstDigit && s[index] != ' ')) { break;}
            index++;
        }

        long high = (pow(2,31)-1);
        long low = pow(-2,31);
        long result_s;
        
        if (result.length() <= 11) {
            result_s = stol(result);
            if (neg != 0) {result_s *= (neg*(-1));}
            
            if(result_s < low) { return low;}
            else if (result_s > high) { return high; }
            else if ((pos > 0 && neg > 0) || (pos>1) || (neg>1)) { return 0;}
            return result_s;
        }
        else {
            if ((pos > 0 && neg > 0) || (pos>1) || (neg>1)) { return 0;}
            else if (neg>0) {return low;}
            return high;
        }
    }
};

int main() {
    StringtoInteger si;
    string s;
    cin >> s;
    cout << si.myAtoi(s) << endl;
}
