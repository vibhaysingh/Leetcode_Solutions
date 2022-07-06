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
    vector<int> postorderTraversal(TreeNode* root) {
        
        // postorder ---> [left right root}
        
        if(!root) return {};
        
        stack<TreeNode*>st;
        
        vector<int>ans;
        
        st.push(root);
        
        while(!st.empty()){
            
            TreeNode* temp = st.top();
            
            ans.push_back(st.top()->val);
            st.pop();
            
            if(temp->left){
                st.push(temp->left);
            }
            
             if(temp->right){
                st.push(temp->right);
            }
        }
        
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
        
        
    }
};