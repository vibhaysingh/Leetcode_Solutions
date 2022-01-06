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
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL||head->next==NULL){
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        do{
            fast = fast->next->next;
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
           
        }
        while(fast!= NULL && fast->next!=NULL);
        
        if(fast==NULL){
            
            fast=slow;
            slow = prev;
        } // even length
        else{
            fast = slow->next;
            slow = prev;
        }
        
        while(slow!=NULL&&prev!=NULL){
            
            if(slow->val!=fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
        
        
    }
};