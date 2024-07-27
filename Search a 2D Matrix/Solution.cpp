// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        int l, r, m;
        for (int i=0; i<matrix.size(); i++) {
            cout << matrix[i][0] << " " << matrix[i][matrix[i].size()-1] << endl;
            if (matrix[i][0]<=target && matrix[i][matrix[i].size()-1]>=target) {
                cout << matrix[i][0] << " " << matrix[i][matrix[i].size()-1] << endl;
                l = 0; r = matrix[i].size()-1;
                int m, f = 0, l = matrix[i].size()-1;
                while (f <= l){
                    m = ((f+l)/2);
                    if (matrix[i][m] == target){return true;}
                    else if (matrix[i][m] > target){l = m-1;}
                    else {f = m+1;}
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int target = 3;
    vector<vector<int>> matrix {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    
    cout << sol.searchMatrix(matrix, target) << endl;
    
    cout << endl;

    return 0;
}
