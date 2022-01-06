/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL||head->next==NULL) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        do{
            slow= slow->next;
            fast= fast->next->next;
            
        }while(fast!=NULL && fast->next!=NULL && slow!=fast);
            
            if(fast==NULL) return false;
        
        if(slow==fast) return true;
        
        return false;
        
    }
};