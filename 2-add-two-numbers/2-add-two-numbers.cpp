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
    
    ListNode* solver(ListNode* l1, ListNode* l2,bool carry){
        
        
        if(carry==false){
            
        if(l1==NULL&&l2==NULL)
            return NULL;        
        else if(l1==NULL) 
            return l2;        
        else if(l2==NULL) 
            return l1;
        }else{
            
         if(l1==NULL&&l2==NULL){
             ListNode* p = new ListNode(1);
             return p;
         }
         else if(l1==NULL){
             
         int sum =  l2->val + carry;
        
        ListNode* p = new ListNode(sum%10);
        
        if(sum>=10)carry=true;
        else carry = false;
        
        p->next = solver(l1,l2->next,carry);
        
        return p;
             
         } 
                  
         else if(l2==NULL) {
             
             int sum = l1->val  + carry;
        
        ListNode* p = new ListNode(sum%10);
        
        if(sum>=10)carry=true;
        else carry = false;
        
        p->next = solver(l1->next,l2,carry);
        
        return p;
             
         }
            
        }
        
        int sum = l1->val + l2->val + carry;
        
        ListNode* p = new ListNode(sum%10);
        
        if(sum>=10)carry=true;
        else carry = false;
        
        p->next = solver(l1->next,l2->next,carry);
        
        return p;
        
        
        
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        return solver(l1,l2,false);
        
        
    }
};