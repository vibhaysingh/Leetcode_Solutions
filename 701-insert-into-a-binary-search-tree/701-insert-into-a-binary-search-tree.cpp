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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root) return new TreeNode(val);
        
        TreeNode* curr = root;
        int l=2;
        
        while(1){
            
            // cout<<curr->val<<endl;
            
            if(curr!=NULL && curr->val < val){
                   
                TreeNode* prev = curr;
                curr = curr->right; 
                
                if(curr==NULL){
                    prev->right = new TreeNode(val);
                    break;
                }
            }
            else if(curr!=NULL && curr->val>val){ 
                // cout<<"here"<<endl;
                  TreeNode* prev = curr;
                curr=curr->left;
                
                 if(curr==NULL){
                    prev->left = new TreeNode(val);
                     
                   
                    break;
                }
            }
           
        }
        
        return root;
        
    }
};