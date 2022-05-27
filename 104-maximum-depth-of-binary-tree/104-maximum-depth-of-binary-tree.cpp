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
    
    int solver(TreeNode* root){
        
        if(!root) return 0;
        
        int l1 = solver(root->left);
        
        int l2 = solver(root->right);
        
        
        return 1+ max(l1,l2);
    }
    
    int maxDepth(TreeNode* root) {
        
        return solver(root);
    }
};