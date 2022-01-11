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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL||head->next==NULL) return head;
        
         ListNode* dummy  = new  ListNode(-200);
        
        
         ListNode*curr=head;
         ListNode*prev = dummy;
         ListNode*prev2 = dummy;
        
        
        while(curr!=NULL){
            
            if(prev->val!=curr->val){
                
                prev->next = curr;
                prev2 = prev;
                prev = curr;
                dummy->val=curr->val;
                curr= curr->next;
                
            }
            else{
                while(curr!=NULL&&prev->val==curr->val){
                    curr=curr->next;
                }
                prev = prev2;
                
            }
            
        }
        prev->next=NULL;
        if(prev==dummy)return NULL;
        return dummy->next;
        
        
    }
};