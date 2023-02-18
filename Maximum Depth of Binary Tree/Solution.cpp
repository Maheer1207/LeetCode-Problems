// Question: https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
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
    
    // [1,2,2,3,4,4,3]
    TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    
    // [0,2,4,1,null,3,-1,5,1,null,6,null,8]
    /*TreeNode *root = newNode(0);
    root->left = newNode(2);
    root->right = newNode(4);
    root->left->left = newNode(1);
    root->right->left = newNode(3);
    root->right->right = newNode(-1);
    root->left->left->left = newNode(5);
    root->left->left->right = newNode(1);
    root->right->left->right = newNode(6);
    root->right->right->right = newNode(8);*/
    
    cout << "Depth of the tree: " << sol.maxDepth(root) << endl;
   
    return 0;
}
