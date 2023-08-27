//Question: https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start=0, net=0, curr = 0, n=gas.size();
        
        for(int i=0; i<n; i++) {
            net += gas[i];
            net -= cost[i];
        }
        
        if (net<0) { return -1; }
        
        for(int i=0; i<n-1; i++) {
            
            curr += gas[i];
            curr -= cost[i];
            
            if (curr<0) { 
                curr = 0;
                start = i+1; 
            }
        }
        
        return start;
    }
};

int main() {
    
    Solution sol;
    
    vector<int> gas{5,8,2,8};
    vector<int> cost{6,5,6,6};
    
    vector<int> gas1{2,3,4};
    vector<int> cost1{3,4,3};
    
    vector<int> gas2{1};
    vector<int> cost2{2};
    
    vector<int> gas3{3};
    vector<int> cost3{2};
    
    vector<int> gas4{1,2,3,4,5};
    vector<int> cost4{3,4,5,1,2};
    
    cout << sol.canCompleteCircuit(gas, cost) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.canCompleteCircuit(gas1, cost1) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.canCompleteCircuit(gas2, cost2) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.canCompleteCircuit(gas3, cost3) <<  endl;
    
    cout << "________" << endl;
    
    cout << sol.canCompleteCircuit(gas4, cost4) <<  endl;
    
    return 0;
}
