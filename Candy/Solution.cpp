#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);
        
        for (int i=1; i<n; i++) {
            if(ratings[i]>ratings[i-1] && candies[i]<=candies[i-1]) { candies[i] = candies[i-1]+1; }
        }
        
        for (int i=n-2; i>=0; i--) {
            if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]) { candies[i] = candies[i+1]+1; }
        }
        
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += candies[i];
        }
        
        return sum;
    }
};

int main() {
    
    Solution sol;
    
    vector<int> ratings{4,3,2,4,1};
    vector<int> ratings1{0,1,2,3};
    vector<int> ratings2{1,0,2};
    vector<int> ratings3{1,2,2};
    vector<int> ratings4{1,3,2,2,1};
    vector<int> ratings5{29,51,87,87,72,12};
    vector<int> ratings6{1,2,3,1,0};
    vector<int> ratings7{1,3,4,5,2};
    
    cout << sol.candy(ratings) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.candy(ratings1) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.candy(ratings2) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.candy(ratings3) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.candy(ratings4) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.candy(ratings5) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.candy(ratings6) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.candy(ratings7) <<  endl;
    return 0;
}
