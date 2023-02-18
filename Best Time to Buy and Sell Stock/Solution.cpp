// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = 0, s = 0, profit = 0;

        for (int i = 1; i<prices.size(); i++) {
            if (prices[i] < prices[b]) {
                b = i;
                s = i;
            }
            else if (prices[i] > prices[s]) { s = i; }

            if (profit < (prices[s]-prices[b])) { profit = prices[s]-prices[b]; }
        }

        return profit;
    }
};

int main() {
    Solution sol;
    
    vector<int> prices {7,1,5,3,6,4};
    
    cout << sol.maxProfit(prices) << endl;

    return 0;
}
