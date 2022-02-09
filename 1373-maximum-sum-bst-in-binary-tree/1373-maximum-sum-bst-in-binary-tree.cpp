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

struct dataa {

    int mn;
    int mx;
    int sz;
    int sum;
    bool isbst;
    TreeNode* node;

};

int ans = INT_MIN;

class Solution {
public:
    
    dataa solver(TreeNode* root){

    if(root==NULL){
     // assume NULL is bst
         ans=max(ans,0);
        return {INT_MAX,INT_MIN,0,0,true,NULL};
    }

    //  assume leaf node is bst

    if(root->left==NULL&&root->right==NULL){
        
         ans=max(ans,root->val);

        return {root->val,root->val,1,root->val,true,root};
    }

    // solve for left and right and make ans for root

    dataa left = solver(root->left);
    dataa right = solver(root->right);

    dataa curr ; // standing at root

    // agr left aur right dono bst hai 
    // left ka max root se chhota ho
    // right ka min root se bda ho

    if(left.isbst && right.isbst && left.mx < root->val && right.mn>root->val){
       
       // update root 

       curr.isbst = true;
       curr.sz =  left.sz+right.sz+1;
       curr.sum = left.sum+right.sum + root->val;
        ans=max(ans,curr.sum);
       curr.node = root;

    //    ans= max(ans,curr.sum);

      // update min for left max for right for root

      if(left.mn!=INT_MAX){
          
          curr.mn = left.mn;
      }
      else{
          curr.mn = root->val;
      }

      if(right.mx!=INT_MIN){

          curr.mx = right.mx;
      }
      else{
          curr.mx = root->val;
      }

      return curr;
       

    }
    else{

        curr.sum = max(left.sum,right.sum);
         // ans=max(ans,curr.sum);
        curr.sz = max(left.sz,right.sz);
        curr.isbst = false;
        curr.mn = INT_MAX;
        curr.mx = INT_MIN;
        curr.node = NULL;

        return curr;
    }

    return curr;
}
    
    int maxSumBST(TreeNode* root) {
        
        ans=INT_MIN;
        
         solver(root);

    return max(0,ans);
        
    }
};