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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head) return head;
        if(head->next==NULL) return NULL;
        
        ListNode* fwd = head;
        ListNode* bwd = head;
        ListNode* prev = NULL;
        n-=1;
        while(n){
            fwd = fwd->next;
            n--;
        }
        while(fwd->next!=NULL){
            
            fwd = fwd->next;
            prev = bwd;
            bwd = bwd ->next;
        }
        
        if(bwd==head){
            return head->next;
        }
        
        
        prev->next = bwd->next;
        
        return head;
        
        
        
    }
};