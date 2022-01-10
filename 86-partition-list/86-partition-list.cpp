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
    ListNode* partition(ListNode* head, int x) {    
        
        ListNode* small = new ListNode(0); // dummy head for samller values
        ListNode* large = new ListNode(0); // dumm head for equal or larger value
       
        ListNode* ans1 = small;
        ListNode* ans2 = large;
        ListNode* next=NULL;
        ListNode* curr = head;
        
        while(curr!=NULL){
            
            next = curr->next;
            if(curr->val<x){
                small->next = curr;
                small = curr;
            }else{
                large->next = curr;
                large = curr;
            }
            curr=next;
        }
        
        large->next=NULL;
        small->next = ans2->next;
        return ans1->next;
    }
};