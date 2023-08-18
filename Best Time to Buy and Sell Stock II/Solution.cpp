//Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for (int i=0; i< prices.size()-1; i++) {
            if(prices[i+1] > prices[i]) {
                profit += (prices[i+1]-prices[i]);
            }
        }
        
        return profit;
    }
};

int main()
{
    Solution sol;
    vector<int>prices{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    
    cout << sol.maxProfit(prices) << endl;
    
    return 0;
}
