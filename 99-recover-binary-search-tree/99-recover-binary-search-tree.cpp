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
    
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    
    void inorder(TreeNode* root){
        
        if(!root) return;
        
        inorder(root->left);
        
        if(first==NULL && prev->val> root->val){
            first = prev;
        }
        
        if(first!=NULL && prev->val>root->val ){
            second = root;
        }
        
        prev = root;
        
        inorder(root->right);
    }
    
    // 1 2 3 4 5
    // 1 5 3 4 2
    
    
    void recoverTree(TreeNode* root) {
        
         first = NULL;
     second = NULL;
 prev = new TreeNode(INT_MIN);
        
        inorder(root);
        
        // cout<<first->val<<" "<<second->val<<endl;
        
        swap(first->val,second->val);
        
    }
};