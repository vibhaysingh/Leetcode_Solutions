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
    
    vector<TreeNode*> solver(int s,int e){
       
        vector<TreeNode*>ans;
        
        if(s>e) return ans={NULL};
        
        for(int i=s;i<=e;i++){
        
        vector<TreeNode*>l=solver(s,i-1);
        vector<TreeNode*>r=solver(i+1,e);
            
            for(auto k:l){
                
                for(auto j:r){
                    
                    TreeNode* root = new TreeNode(i);
                    
                    root->left = k;
                    root->right = j;
                    
                    ans.push_back(root);
                }
            }
            
            
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return solver(1,n);
    }
};