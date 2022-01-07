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
    
    Node * solver(Node* head){
        
        if(head==NULL) return NULL;
        
        while(head->next!=NULL){ // go  till second last node
            
        if(head->child){ // if child exist at this node 
            Node * next  = head->next; // store the next pointer            
            Node* tail = solver(head->child); // flatten the child and store its tail            
            head->next= head->child; // make head next the child pointer 
            head->child->prev = head; // make doubly linked list
            head->child = NULL; // nullify the child here             
            tail->next = next; // point the flattend child tail to head next stored above
            next->prev = tail; //make doubly linked list
            head = next;  // move head further
            
        }
        else{
             head= head->next;
            
        }            
    }
        
        // last node reached 
        // just check if it has child or not
        if(head->child != NULL){ 
            
            Node* tail = solver(head->child);
            
            head->next= head->child; // make head next the child pointer  
            head->next->prev = head; // make doubly linked list
            head->child = NULL; // nullify the child here
            head = tail;
           
        }
        // cout<<head->val<<endl;
        return head ; // return the last head ie tail
    }
    
    Node* flatten(Node* head) {
        
        if(head==NULL) return NULL;
        
        solver(head); 
        
        return head;
        
    }
};