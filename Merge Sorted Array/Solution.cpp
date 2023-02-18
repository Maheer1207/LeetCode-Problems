// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> merged;
        int nPtr = n-1, mPtr = m-1, total = m+n-1;

        while (mPtr>=0 && nPtr>=0) {
            if (nums1[mPtr] > nums2[nPtr]) {
                nums1[total] = nums1[mPtr];
                total--;
                mPtr--;
            }
            else {
                nums1[total] = nums2[nPtr];
                total--;
                nPtr--;
            }
        }
        while(nPtr>=0)nums1[total--]=nums2[nPtr--];
    }
};

int main() {
    Solution sol;
    
    int m = 3, n= 3;
    vector<int> nums1{1,2,3,0,0,0}, nums2{2,5,6};
    
    sol.merge(nums1, m, nums2, n);
    
    for (auto i: nums1) {
        cout << i << " ";
    }
    
    cout << endl;

    return 0;
}
