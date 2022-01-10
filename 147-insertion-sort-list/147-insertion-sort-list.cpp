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
    
   
    
    ListNode* insertionSortList(ListNode* head) {
        
        
        ListNode * p1 = head;
        ListNode * prev1 = NULL;
        ListNode * next1 = NULL;
        
        while(p1!=NULL){
   
          ListNode * p2 = head;  
        
            
    
            while(p2!=p1){
                
                
                if(p2->val<=p1->val){
                    
                    p2 = p2->next;
                    continue;
                }
                                
                    swap(p1->val,p2->val);
                    
                
                // break;
                
            }
            
            // ListNode* x = head;
            // while(x!=NULL){
            //     cout<<x->val<<" ";
            //     x=x->next;
            // }
            // cout<<endl;
           
            p1 = p1->next;
        
        } 
        
        return head;
        
        
    }
};