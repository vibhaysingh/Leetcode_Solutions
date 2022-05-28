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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        q.push(root);
        
        
        while(!q.empty()){
            
            int l = q.size();
            vector<int>v;
            while(l--){
                
                auto x = q.front();
                q.pop();
                v.push_back(x->val);
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            ans.push_back(v);
        }
        
        return ans;
        
        
        
    }
};