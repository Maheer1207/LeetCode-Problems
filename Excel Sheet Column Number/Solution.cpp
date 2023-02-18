// Question: https://leetcode.com/problems/excel-sheet-column-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int val = 0;
        for (int i = columnTitle.size()-1; i >= 0; i--) {
            val += ((int(columnTitle[i])-64)*(pow(26, (columnTitle.size()-1-i))));
        }
        return val;
    }
};

int main() {
    Solution sol;
    
    /*A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28*/
    string n;
    
    cin >> n;
    
    cout << sol.titleToNumber(n) << endl;

    return 0;
}
