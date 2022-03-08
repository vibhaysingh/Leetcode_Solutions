/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root==NULL) return {};
        
        vector<vector<int>>ans;
        
        queue<Node*>q;
        
        vector<int>temp;
        // temp.push_back(root->val);
        // ans.push_back(temp);
        q.push(root);
        
        while(!q.empty()){
            
            int l = q.size();
              temp.clear();
            
            for(int i=0;i<l;i++){
                
                auto k = q.front();
                q.pop();
                temp.push_back(k->val);
                
                for(auto ch:k->children){
                    
                    // cout<<"f"<<ch->val<<endl;
                    
                   q.push(ch);
                }
            }
            
            ans.push_back(temp);
            
           
          
        }
        
        return ans;
        
    }
};