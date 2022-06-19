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
    #define need  1
#define have  0
#define covered -1
    
    int count=0;
    int solver(TreeNode* root){
        
        if(root==NULL) return covered;
        
        int l = solver(root->left);
        int r = solver(root->right);
        
        if(l==covered && r==covered){
            
            return need;
        }
         if(l==need||r==need){
            count++;
            return have;
        }
       if(l==have||r==have){
            return covered;
        }
        
       return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        
       
        count=0;
        if(solver(root)==need)count++;
     
       return count;
    }
};