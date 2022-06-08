/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*,Node*>mp;
    Node* clone(Node* par){
        
        if(par==NULL) return NULL;
        
        Node* copypar = new Node(par->val);
        mp[par]=copypar;
        
        for(auto k:par->neighbors){
            
            if(mp.find(k)==mp.end())
            copypar->neighbors.push_back(clone(k));
            else{
                
                copypar->neighbors.push_back(mp[k]);
            }
        }
        
        return copypar;
    }
    
    Node* cloneGraph(Node* node) {
        
        return clone( node);
    }
};