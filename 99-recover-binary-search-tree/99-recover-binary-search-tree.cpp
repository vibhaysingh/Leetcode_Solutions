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
    
    vector<int>v;
    void in(TreeNode* root){
        
        if(!root) return;
        
       
        in(root->left);
         v.push_back(root->val);
        in(root->right);
        
        
    }
    
    TreeNode* c;TreeNode* d;
    
    void solver(TreeNode* root,int a,int b)
    {
        
        if(root==NULL) return;
        
        if(root->val==a){
            c=root;
        }
        else if(root->val==b){
            d=root;
        }
        
        solver(root->left,a,b);
        solver(root->right,a,b);
    }
    
    
    void recoverTree(TreeNode* root) {
        
        v.clear();
        in(root);
        
        vector<int>a=v;
        sort(a.begin(),a.end());
        
        int x,y;
        
        
        
        for(int i=0;i<a.size();i++){
            
            cout<<a[i]<<" "<<v[i]<<endl;
            
            if(a[i]!=v[i]){
                x=a[i];
                y=v[i];
                break;
            }
        }
        
        cout<<x<<y<<endl;
        solver(root,x,y);
        
        cout<<c->val<<" "<<d->val<<endl;
        
        swap(c->val,d->val);
        
        
    }
};

 