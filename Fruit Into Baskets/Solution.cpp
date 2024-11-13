//Question: https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        set<int> typeF;
        int cnt=0, res=0, lastConsc=1;
        
        for (int i=0; i<fruits.size(); i++) {
            if (typeF.find(fruits[i]) == typeF.end()) {
                cout << fruits[i] << " ";
                if (typeF.size() < 2){
                    typeF.insert(fruits[i]);
                    cnt++;
                } else {
                    res = res<cnt ? cnt:res;
                    cnt = 0;
                    
                    int x = fruits[i-1];
                    typeF.erase(typeF.begin(), typeF.end());
                    
                    typeF.insert(x);
                    typeF.insert(fruits[i]);
                    cnt = lastConsc + 1 ;
                }
                lastConsc = 1;
            } else { 
                cnt++;
                if (fruits[i] == fruits[i-1]) lastConsc++;
                else lastConsc=1;
            }
        }
        
        res = res<cnt ? cnt:res;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> fruits {1,2,3,2,2};
    
    cout << sol.totalFruit(fruits) << endl;
    
    cout << endl;

    return 0;
}
