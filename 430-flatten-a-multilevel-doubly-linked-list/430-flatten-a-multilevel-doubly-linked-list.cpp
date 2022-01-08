/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        Node* curr=head;
        
        while(curr!=NULL){
            
            if(curr->child==NULL){
                curr=curr->next;
                continue;
            }
            
            Node* temp = curr->child;
            
            while(temp->next!=NULL){
                temp=temp->next;
            }
            
            temp->next  = curr->next;
            
            if(curr->next){
                curr->next->prev = temp;
            }            
            curr->next = curr->child;
            curr->child->prev = curr;
            curr->child = NULL;
        }
        
        return head;
        
    }
};