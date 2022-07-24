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
    
    TreeNode* solver(TreeNode* root){
        
        if(root->left==NULL) return root->right;
        
        if(root->right==NULL ) return root->left;
        
        TreeNode* rightchild = root->right;
        TreeNode* lastChildInLeft = findLast(root->left);
        lastChildInLeft->right= rightchild;
        return root->left;
    }
    
    TreeNode* findLast(TreeNode* root){
        
        if(root->right==NULL) return root;
        return findLast(root->right);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL) return NULL;
        
        if(root->val==key)
            return solver(root);
        TreeNode* temp=root;
        
        while(root!=NULL){
            
            if(root->val>key){
              
                if(root->left!=NULL && root->left->val==key){
                    
                    root->left = solver(root->left);
                    
                }
                else{
                    root= root->left;
                }
            }
            else if(root->val<key){
                
                if(root->right!=NULL && root->right->val==key){
                    
                    root->right = solver(root->right);
                    
                }
                else{
                    root= root->right;
                }
                
            }
        }
        
        return temp;
        
    }
};