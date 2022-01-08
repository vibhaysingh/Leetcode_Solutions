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
    Node* copyRandomList(Node* head) {
        
        if(head==NULL) return NULL;
        
        Node* curr = head;
        Node* next = NULL;
        
        
        
        while(curr!=NULL){
            
            Node* copy = new Node(curr->val);            
            next = curr->next;
            curr->next = copy;
            copy->next = next;
            curr=next;            
        }
        
        curr = head;
        
        // point all the random pointers
        while(curr!=NULL){
            
            // if random is not null
            if(curr->random)
            curr->next->random = curr->random->next;
            curr=curr->next->next;
        }
        
        Node* ans  = head->next;
        curr=head;
        // restore the original list;
        Node* temp;
        while(curr!=NULL){
            
            next = curr->next;
            curr->next = curr->next->next;            
            temp =  next->next;  
            if(next->next)
            next->next = temp->next;
            curr=temp;
            
        }
        
        return ans;
        
        
        
    }
};