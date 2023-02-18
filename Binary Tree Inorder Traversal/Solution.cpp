// Question: https://leetcode.com/problems/binary-tree-inorder-traversal/

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

    // [3,9,20,null,null,15,7]
    /*TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);*/
    
    // [0,2,4,1,null,3,-1,5,1,null,6,null,8]
    TreeNode *root = newNode(0);
    root->left = newNode(2);
    root->right = newNode(4);
    root->left->left = newNode(1);
    root->right->left = newNode(3);
    root->right->right = newNode(-1);
    root->left->left->left = newNode(5);
    root->left->left->right = newNode(1);
    root->right->left->right = newNode(6);
    root->right->right->right = newNode(8);
    
    
    vector<int> result = sol.inorderTraversal(root);
    
    cout << "Inorder traversal : ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    cout << endl;
   
    return 0;
}
