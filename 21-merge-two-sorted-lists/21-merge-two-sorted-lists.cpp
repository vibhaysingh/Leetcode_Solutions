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
     ListNode* merge(ListNode* list1, ListNode* list2){
         
         if(list1==NULL) return list2;
         
         if(list2== NULL) return list1;
         
         if(list1->val<=list2->val) {
             
              list1->next = merge(list1->next,list2);
             return list1;
         }else{
             
              list2->next = merge(list1,list2->next);
             return list2;
         }
         
         return NULL;
         
     }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //return merge(list1,list2);
        
        if(list1==NULL) return list2;
        
        if(list2== NULL) return list1;
        
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* res = NULL;
        ListNode* temp = NULL;
        
        if(l1->val > l2->val){
            swap(l1,l2);
        }
        
        res = l1;
        
        while(l1!= NULL && l2!=NULL){
            
            temp = NULL;
           
            while( l1 != NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }
            // cout<<l1->val<<l2->val<<temp->val<<endl;
            temp->next = l2;
            swap(l1,l2);
            
        }
        
        
        return res;
        
        
        
    }
};