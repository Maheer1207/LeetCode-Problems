class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, res=0, maxf=-1;
        unordered_map<char, int> hmap;
        
        for (r; r<s.length(); r++) {
            hmap[s[r]]++;
            for (auto ele: hmap) { if (maxf<ele.second) { maxf = ele.second; } }
            if ((r-l+1)-maxf > k) {
                hmap[s[l]]--;
                l++;
            }
            if (res<(r-l+1)) { res=(r-l+1); }
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    
    string s = "AABABBA";
    int k = 1;
    
    cout << sol.characterReplacement(s, k) << endl;
    
    return 0;
}
