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
    
    int ans;
    
    int solver(TreeNode* root){
        
        if(!root) return 0;
        
        int l = solver(root->left);
        int r = solver(root->right);
        
        ans=max(ans,abs(l-r));
        
        return 1+max(l,r);
    }
    
    bool isBalanced(TreeNode* root) {
        
        ans=0;
        
        solver(root);
        
        return ans<2;
    }
};