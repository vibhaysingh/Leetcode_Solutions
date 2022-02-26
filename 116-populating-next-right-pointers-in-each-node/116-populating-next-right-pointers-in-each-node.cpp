/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
//     void solver(Node*root,Node* temp){
        
//         if(root==NULL) return;
        
//         solver(root->left);
//         solver(root->right);
        
//         if(root->left && root->right){
            
//             root->left->next = root->right;
//             root->right->next = temp;
//         }
        
        
//     }
    
    Node* connect(Node* root) {
        
        // solver(root,NULL);
        
        if(root==NULL) return root;        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int x = q.size();
            
            while(x--){
                
                Node* curr = q.front();
                q.pop();
                
                if(x) {
                    curr->next = q.front();
                }
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        
        return root;
    }
};