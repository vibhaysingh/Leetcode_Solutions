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
    bool isValidBST(TreeNode* root) {
        
        stack<TreeNode*>st;
        TreeNode* curr=root;
       
        TreeNode* prev = NULL;
        
        while(curr!=NULL || !st.empty() ){
            
            while(curr!=NULL){
                
                st.push(curr);
                curr=curr->left;
            }
            
            curr=st.top();
            st.pop();
            if(prev!=NULL && prev->val>=curr->val) return false;
                prev = curr;
                
             curr= curr->right;   
            
        }
        
        return true;
        
        
    }
};