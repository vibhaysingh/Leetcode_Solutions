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
    
    void solver(TreeNode* root,unsigned long long int idx,int level,vector<pair<int,int>>&v){
        
        if(!root) return;
        
        if(v.size()==level){
            
            v.push_back({idx,idx});
        }
        else{
            
            v[level].second = idx;
        }
        
        ans= max(ans,abs(v[level].first-v[level].second)+1);
        
        solver(root->left,2LL*idx+1,level+1,v);
        solver(root->right,2LL*idx+2,level+1,v);
        
        
        
        
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        
        ans=0;
        
        vector<pair<int,int>>v;
        
        solver(root,0,0,v);
        
        return ans;
        
    }
};