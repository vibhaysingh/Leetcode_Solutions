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
    
    
    int len(ListNode* head){
        
        if(head==NULL) return 0;
        
        return 1+ len(head->next);
    }
    
    int add(ListNode* l1,ListNode*l2,int len1,int len2){
        
        if(len1==0) return 0;
        
        if(len2<len1){
          
            
            int carry  = add(l1->next,l2,len1-1,len2);
           
            
            if(carry){
                
                l1->val+=carry;
                
                int p = l1->val/10;
                l1->val%=10; 
                
                
                return p;
               
            }
            
            
            
            return 0;
            
        }
        else if(len1==len2){
            
            int carry = add(l1->next,l2->next,len1-1,len2-1);
            
            int val = l2->val+carry;
            
             l1->val+=val;
            
             if(l1->val>=10){
                 
                 l1->val%=10;
                 
                 return 1;
             }
            
            return 0;
            
        }
        
        return 0;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int len1= len(l1);
        int len2= len(l2);
        
        // cout<<len1<<" "<<len2<<endl;
        
        if(len1<len2){
            swap(l1,l2);
            swap(len1,len2);
        }
        
        // l1 is bigger now;
        
        int carry = add(l1,l2,len1,len2);
        
        if(carry){
            
            ListNode* t = new ListNode(carry);
            
            t->next=l1;
            
            return t;
        }
        
        return l1;
        
    }
};