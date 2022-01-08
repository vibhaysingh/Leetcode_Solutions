/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*,Node*>mp; // < old,new >
    
    Node* solver(Node* head){
        
        if(head==NULL){
            return NULL;
        }
        
        Node * new_head = new Node(head->val);
        
        mp[head]=new_head;
        new_head->next = solver(head->next);
        
        if(head->random!=NULL){
            
            new_head->random = mp[head->random];
        }
        
        return new_head;
        
    }
    
    Node* copyRandomList(Node* head) {
        
       return solver(head); 
        
    }
};