/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int Length(ListNode* head){
        
        if(head==NULL) 
            return 0;
        
        return 1 + Length(head->next);
    }
    
    ListNode* th = NULL; // temporary head
    ListNode* tt = NULL; // temporary tail
    
    void addFirst(ListNode* node){
        
        if(th==NULL){
            th = node;
            tt = node;
            
        }else{
            node->next = th;
            th = node;
            
        }
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL||head->next==NULL||k==0) return head;
        
        int len = Length(head);
        
        ListNode* curr = head;
        ListNode* oh = NULL; // original head
        ListNode* ot = NULL; // original tail
        
        // cout<<len<<k<<endl;
        
        while(len>=k){
            
            for(int i=0;i<k;i++){
                
                ListNode * next = curr->next;
                curr->next = NULL;
                // cout<<curr->val<<" x"<<endl;
                addFirst(curr);
                curr=next;
                
            }
            
            ListNode* x = th;
            
            
            // while(x!=NULL){
            //     cout<<x->val<<" ";
            //     x=x->next;
            //     cout<<endl;
            // }
            
            if(oh==NULL){
                
                oh = th;
                ot = tt;
                
            }else{
                
                ot->next = th;
                ot = tt;
                
            }
            
            th = NULL;
            tt = NULL;
            len-=k;
            
            
        }
        
        ot->next = curr;
        
        return oh;
        
        
    }
};