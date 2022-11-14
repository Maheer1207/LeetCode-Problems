// Question: https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:int maxArea(vector<int>& height) {
        int area = 0, i = 0, j = height.size()-1;
        while (i!=j) {
            area = max(area, ((j-i)*(min(height[i], height[j]))));
            if (height[i] < height[j]) { i++; }
            else { j--; }
        }
        return area;
    }
};

int main() {
    Solution s;
    vector<int> height{1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(height) << endl;
}
