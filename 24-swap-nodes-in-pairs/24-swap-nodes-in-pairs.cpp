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
    ListNode* swapPairs(ListNode* head) {
        
       if(head==NULL || head->next == NULL) return head;
        
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* left=NULL;
        ListNode* right=NULL;
        
        left = head;
        right = head->next;
        next= head->next->next;
        
        right->next = left;
        left->next=next;
        head = right;
        
        if(next==NULL) return head;
        prev = head->next;
        left = prev->next;
        right = left->next;
        
        while(right!=NULL){
            
            next = right->next;
            right->next = left;
            prev->next = right;
            left->next = next;
            
            prev = left;
            left = left->next;
            if(left==NULL) break;
            right = left->next;
            if(right==NULL) break;
            next  = right->next;
            
        }
        
      return head;  
        
    }
};