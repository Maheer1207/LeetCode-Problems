#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main()
{
   Solution sol;
   vector <string> strs{"eat","tea","tan","ate","nat","bat"};
   
   vector<vector<string>> res;
   vector<string> grp;
   
   res = sol.groupAnagrams(strs);
   
   for(int i=0; i<res.size(); i++){
       grp = res[i];
       for(int j=0; j<grp.size(); j++) {
           cout << grp[j] << " "; 
       }
       cout << endl;
   }            
   
   return 0;
}
