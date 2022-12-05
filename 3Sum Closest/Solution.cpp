// Question: https://leetcode.com/problems/3sum-closest/

#include <bits/stdc++.h>
using namespace std;
 
 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n=nums.size();
        int result;
        int diff=INT_MAX;

        if(n<3) return {};

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                 int sum=nums[i]+nums[j]+nums[k];

                if(abs(sum-target) < diff)
                {
                    diff=abs(sum-target);
                    result=sum;
                }

                if(sum > target) k--;

                else j++;
            }
        }        

       return result;
    }
};
 
 
int main()
{
   Solution sol;
   vector <int> nums{-1,2,1,-4};
   int target = 1;
   
   cout << sol.threeSumClosest(nums, target) << endl;

    return 0;
}
