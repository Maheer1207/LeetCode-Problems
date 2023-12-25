#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row, column, sqr;

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] != '.') { 
                    row[board[i][j]]++; 
                    if (row[board[i][j]]>1) return false;
                }
                if (board[j][i] != '.') { 
                    column[board[j][i]]++; 
                    if (column[board[j][i]]>1) return false;
                }
            }
            row.clear();
            column.clear();
        }

        for (int i=0; i<9; i+=3) {
            for (int j=0; j<9; j+=3) {
                sqr.clear();
                for (int x=i; x<i+3; x++) {
                    for (int y=j; y<j+3; y++) {
                        if (board[x][y] != '.') {
                            sqr[board[x][y]]++;
                            if (sqr[board[x][y]]>1) return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
   Solution sol;
   vector<char> r1 {'5','3','.','.','7','.','.','.','.'};
   vector<char> r2 {'6','.','.','1','9','5','.','.','.'};
   vector<char> r3 {'.','9','8','.','.','.','.','6','.'};
   vector<char> r4 {'8','.','.','.','6','.','.','.','3'};
   vector<char> r5 {'4','.','.','8','.','3','.','.','1'};
   vector<char> r6 {'7','.','.','.','2','.','.','.','6'};
   vector<char> r7 {'.','6','.','.','.','.','2','8','.'};
   vector<char> r8 {'.','.','.','4','1','9','.','.','5'};
   vector<char> r9 {'.','.','.','.','8','.','.','7','9'};
   
   vector<vector<char>> board{r1,r2,r3,r4,r5,r6,r7,r8,r9};
   
   cout << sol.isValidSudoku(board) << endl;
   
   return 0;
}
