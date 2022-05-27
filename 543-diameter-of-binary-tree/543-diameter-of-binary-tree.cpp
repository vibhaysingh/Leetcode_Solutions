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
    
    int dia(TreeNode* root){
        
        if(!root) return 0;
        
        int l = dia(root->left);
        int r = dia(root->right);
        
        ans= max(ans,l+r+1);
        l++;
        r++;
        return max(l,r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        ans=0;
        dia(root);
        
        if(!ans) return ans;
        
        return ans-1;
    }
};