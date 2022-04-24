/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(!root) return 0;  
      int level = 1;
      int ll = traverse(root->left, level);
      int lr = traverse(root->right, level);
      return ll > lr ? ll : lr;
    }
private: 
    int traverse(TreeNode* node,int level) {
      if(!node) return level;
      int ll = traverse(node->left, level+1);
      int lr = traverse(node->right, level+1);
      return ll > lr ? ll : lr;
    }
};
