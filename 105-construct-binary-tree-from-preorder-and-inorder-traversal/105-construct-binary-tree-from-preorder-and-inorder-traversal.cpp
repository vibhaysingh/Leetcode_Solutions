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
     
     TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &idx, map<int,int>&mp,int l,int r){
         
         int n = inorder.size();
         
         if(idx>=n || l>r ) return NULL;
         
         TreeNode* root = new TreeNode(preorder[idx]);
         
         int mid = mp[preorder[idx]];
         idx++;
         
          TreeNode* left= build(preorder,inorder,idx,mp,l,mid-1);
          TreeNode* right= build(preorder,inorder,idx,mp,mid+1,r);
         root->left = left;
         root->right = right;
         
         return root;
         
     }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // pre -->  root left right
        // in --> left root right
        // post --> left right root
        
        map<int,int>mp;
        
        for(int i=0;i<inorder.size();i++){
            
            mp[inorder[i]]=i;
        }
         
        int idx=0;
        
        return build(preorder,inorder,idx,mp,0,inorder.size()-1);
        
        
        
    }
};