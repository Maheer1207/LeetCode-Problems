// Question: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        stack.push(-1);
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (stack.top() != -1 && heights[i] <= heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = i - stack.top() - 1;
                max_area = max(max_area, height * width);
            }
            stack.push(i);
        }

        while (stack.top() != -1) {
            int height = heights[stack.top()];
            stack.pop();
            int width = heights.size() - stack.top() - 1;
            max_area = max(max_area, height * width);
        }

        return max_area;        
    }
};

int main() {
    Solution sol;
    vector<int> heights {2,1,5,6,2,3};
    
    cout << sol.largestRectangleArea(heights) << endl;
    
    cout << endl;

    return 0;
}
