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
    
    long long sum=0;
    
    int m = 1e9+7;
    
    void inorder(TreeNode* root){
        
        if(!root) return ;
        
        sum+=root->val;
        
        inorder(root->left);
        inorder(root->right);
        
    }
    
    long long ans=1;
    
    int solver(TreeNode* root){
        
        if(!root) return 0;
        
        long int l = solver(root->left);
        long int r = solver(root->right);
        
        long long rem = sum-l;
        long long rem1 = sum-r;
            
            ans  = max(ans,(l*rem));
            ans  = max(ans,(r*rem1));
        
        return l+r+root->val;
            
        
        
        
        
    }
    
    int maxProduct(TreeNode* root) {
        ans=1;
        sum=0;
        
        inorder(root);
        
         solver(root);
        return (ans%m);
        
    }
};