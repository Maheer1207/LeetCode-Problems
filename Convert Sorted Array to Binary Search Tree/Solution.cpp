// Question: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <iostream>
#include <stack>
#include <vector>


using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

// New node creation
TreeNode *newNode(int data) {
  TreeNode* node = new TreeNode();

  node->val = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedSubArrayToBST(0, nums.size()-1, nums);
    }

    TreeNode* sortedSubArrayToBST(int s, int f, vector<int>& nums) {
        if (s > f) { return NULL; }

        int m = (s+f)/2;
        TreeNode* root = newNode(nums[m]);
        
        root->left = sortedSubArrayToBST(s, m-1, nums);
        root->right = sortedSubArrayToBST(m+1, f, nums);

        return root;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inOrder;

        while (node || (!st.empty())) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            inOrder.push_back(node->val);
            node = node->right;
        }

        return inOrder;
    }
};
 
 
int main()
{
    Solution sol;
    
    vector<int> nums{-10,-3,0,5,9};
    
    TreeNode* resultTN = sol.sortedArrayToBST(nums);
    
    vector<int> resultV = sol.inorderTraversal(resultTN);
    
    cout << "Inorder traversal : ";
    for (int i = 0; i < resultV.size(); i++) {
        cout << resultV[i] << " ";
    }
   
    return 0;
}
