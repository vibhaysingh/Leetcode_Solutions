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
class BSTIterator {
public:
    
    stack<TreeNode*>st;
    
    TreeNode* curr;;
    BSTIterator(TreeNode* root) {
        
        curr=root;
        while(curr!=NULL){
            
            st.push(curr);
            curr=curr->left;
        }
        
    }
    
    int next() {
        
        TreeNode* temp = st.top();
        st.pop();
        
        int val = temp->val;
        
        if(temp->right!=NULL){
            
            temp=temp->right;
            
            while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        }
        
        
        return val;
        
    }
    
    bool hasNext() {
        
        return !st.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */