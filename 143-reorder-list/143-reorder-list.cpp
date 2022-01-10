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
    void reorderList(ListNode* head) {
        
        if(head==NULL||head->next==NULL)
            return;
        
        ListNode* curr = head;
        ListNode* slow =head;
        ListNode* prev =NULL;
        ListNode* next =NULL;
        ListNode* fast =head->next;
        ListNode* oddmid =NULL;
        
        // find mid 
        
        while(fast!=NULL && fast->next!=NULL){
            
            prev = slow;
            slow = slow->next;
            
            fast = fast->next->next;
        }
        
        curr = slow->next;
        
        if(fast==NULL){
            
            oddmid=slow;
            slow = prev;
        }
        
        // cout<<slow->val<<" "<<fast->val<<endl;
        
        // reverse after mid
        
        
        slow->next=NULL;
        prev = NULL;
        next = NULL;
        while(curr!=NULL){
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;            
        }
        
        ListNode* p1 = head;
        ListNode* p2 = prev;
        ListNode* next2 = NULL;
        
        // while(p2!=NULL){
        //     cout<<p2->val<<endl;
        //     p2=p2->next;
        // }
        // cout<<p1->val<<" "<<p2->val<<endl;
        while(p1!=NULL){
            
            prev = p2;
            next = p1->next;
            next2 = p2->next;
            p1->next = p2;
            p2->next = next;
            p1=next;
            p2 = next2;
            
        }
        
        if(oddmid){
            
            prev->next = oddmid;
            oddmid->next = NULL;
        }
        
        
        
        
        
    }
};