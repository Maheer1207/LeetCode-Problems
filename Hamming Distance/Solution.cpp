// Question: https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        if (x==y) return 0;

        vector<int> binX(31,0), binY(31,0);
        int cnt_i=30;
        
        while (cnt_i>=0) {
            if (x!=0 && pow(2, cnt_i)<=x) {
                binX[cnt_i]=1;
                x -= pow(2, cnt_i);
            }
            if (y!=0 && pow(2, cnt_i)<=y) {
                binY[cnt_i]=1;
                y -= pow(2, cnt_i);
            }
            
            cnt_i--;
        }
        
        cnt_i=30;
        int cnt=0;
        while (cnt_i>=0) {
            if (binX[cnt_i]!= binY[cnt_i]) { cnt++; }
            cnt_i--;
        }
        
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<string> result;
    
    result = sol.hammingDistance(93, 73);
    
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}
