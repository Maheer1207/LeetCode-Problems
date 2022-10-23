#Question: https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>
using namespace std;

class ReverseInteger {
    public:int findReverse(int x) {
        string val, rev = "";
        val = to_string(x);

        int neg = 0, index = val.length()-1;
        long rev_x;

        while (index >= 0) {
            if (val[index] != '-'){ rev += val[index]; }
            else { neg++; }
            index--;
        }

        rev_x = stol(rev);
        if (neg != 0) {rev_x *= (neg*(-1));}
        
        long high = (pow(2,31)-1);
        long low = pow(-2,31);
        if(rev_x >= low &&  rev_x <= high) { return rev_x; }
        else { return 0; }     
    }
};

int main() {
    ReverseInteger ri;
    int x;
    cin >> x;
    cout << ri.findReverse(x) << endl;
}
