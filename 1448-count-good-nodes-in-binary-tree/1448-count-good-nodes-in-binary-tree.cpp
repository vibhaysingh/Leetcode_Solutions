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
    
    int ans=0;
    
    void dfs(TreeNode*root, int x){
        
        if(root==NULL) return;
        int temp=x;
        
        if(root->val>=x){
            ans++;
            x = max(root->val,x);
        }
        
        dfs(root->left,x);
        dfs(root->right,x);
        x=temp;
    }
    
    int goodNodes(TreeNode* root) {
       
        ans=0;
        int val = -100000;
        dfs(root,root->val);
        return ans;
    }
};