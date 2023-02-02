// Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        unordered_set<char> visited;
        
        int maxStr = 0;

        for(int r=0;r<n;r++)
        {
            if(visited.find(s[r])==visited.end())
            {
                visited.insert(s[r]);
                maxStr = max(maxStr,r-l+1);
                
            }
            else
            {
                while(l!=r && s[l]!=s[r])
                    visited.erase(s[l++]);
                
                //Removing and adding the same element
                visited.erase(s[l++]);
                visited.insert(s[r]);
                
                maxStr = max(maxStr,r-l+1);
            }
        }
        
        return maxStr;
    }
};
 
 
int main()
{
    Solution sol;
    
    string s;
    // s = "abcabcbb";
    cin >> s;
    
    cout << sol.lengthOfLongestSubstring(s) << endl;
   
    return 0;
}
