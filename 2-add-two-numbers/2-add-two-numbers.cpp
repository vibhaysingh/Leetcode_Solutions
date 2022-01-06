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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        bool carry=false;
        
        ListNode* dummy  = new ListNode(-1);
        ListNode* curr=dummy;
        
        while(l1!=NULL && l2!=NULL){
            
            int a = l1->val;
            int b = l2->val;
            
            int ttl = a+b+carry;
            
            if(ttl>=10){
                carry=true;
            }else
                carry = false;
            ListNode* temp  = new ListNode(ttl%10);
            curr->next = temp;
            
            curr = temp;
            l1=l1->next;
            l2= l2->next;
            
            
        }
        
        while(l1!=NULL){
            int a = l1->val;           
            int ttl = a+carry;
            
            if(ttl>=10){
                carry=true;
            }else
                carry = false;
            ListNode* temp  = new ListNode(ttl%10);
            curr->next = temp;
            
            curr = temp;
            l1=l1->next;
            
        }
        
        while(l2!=NULL){
       
            int b = l2->val;
            
            int ttl = b+carry;
            
            if(ttl>=10){
                carry=true;
            }else
                carry = false;
            ListNode* temp  = new ListNode(ttl%10);
            curr->next = temp;
            
            curr = temp;
            l2= l2->next;
        }
        
        if(carry){
            ListNode* temp  = new ListNode(1);
            curr->next = temp;
        }
        
        return dummy ->next;
        
    }
};