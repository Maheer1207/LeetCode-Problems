#Question: https://leetcode.com/problems/zigzag-conversion/

#include <bits/stdc++.h>
using namespace std;

class ZigzagConversion {
public:
    string convert(string s, int numRows) {
        int index, col = numRows;
        string result = "";
        col = numRows;
        if (s.length() < numRows) { col = s.length(); }
        for (int i=0; i<col; i++) {
            index = i;
            result += s[index];
            while ((index <= s.length()-1)) {
                if (numRows < 3) {
                    index += numRows;
                    if ((index <= s.length()-1)){result += s[index];}
                }
                else {
                    if (i != 0 && i != numRows-1) {
                        index += ((numRows*2)-2)-(i*2);
                        if ((index <= s.length()-1)){result += s[index];}
                        index += (i*2);
                        if ((index <= s.length()-1)){result += s[index];}
                    }
                    else {
                        index += ((numRows*2)-2);
                        if ((index <= s.length()-1)){result += s[index];}
                    }
                }
            }
        }
        return result;   
    }
};

int main() {
    ZigzagConversion zc;
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << zc.convert(s, numRows) << endl;
}
