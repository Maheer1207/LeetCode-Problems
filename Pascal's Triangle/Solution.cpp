// Question: https://leetcode.com/problems/pascals-triangle/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> result(numRows);
       vector<int> pRow, row;

       for (int i = 0; i < numRows; i++) {
           result[i].resize(i+1, 1);

           for (int j = 1; j < i; j++) {
               result[i][j] = result[i-1][j-1]+result[i-1][j];
            }
       }
       return result;        
    }
};

int main() {
    Solution sol;
    
    int numRows;
    cin >> numRows;
    
    vector<vector<int>> result = sol.generate(numRows);
    
    for (auto i: result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
