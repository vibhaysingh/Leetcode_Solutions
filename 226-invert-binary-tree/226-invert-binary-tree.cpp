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
    
   TreeNode* solver( TreeNode* root){
         
       if(!root) return NULL;
       
     TreeNode* l1 = solver(root->left);
      TreeNode* l2 = solver(root->right);
       
       root->left = l2;
       root->right = l1;
       
       return root;
       
        
         
     }
    
    TreeNode* invertTree(TreeNode* root) {
        return solver(root);
        
        return root;
    }
};