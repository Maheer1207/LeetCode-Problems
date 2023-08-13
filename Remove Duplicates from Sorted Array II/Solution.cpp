//Question:

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1, cnt = 1;
        int swap, current = nums[i];
        
        while (j < nums.size()) {
            if(current != nums[j]) {
                cnt = 0;
                current = nums[j];
                
                swap = nums[j];
                nums[j] = nums[i+1];
                nums[i+1] = swap;
                i++;
                cnt++;
            }
            
            else {
                cnt++;
                if(cnt<=2){
                    swap = nums[j];
                    nums[j] = nums[i+1];
                    nums[i+1] = swap;
                    i++;
                }
            }
            j++;
        }
        
        return i++;
    }
};


int main()
{
    Solution sol;
    vector<int>nums{1,1,1,2,2,3};
    
    int result = sol.removeDuplicates(nums);
    
    
    for(int ind = 0; ind <= result; ind++) {
        cout << nums[ind] << endl;
    }
    
    return 0;
}
