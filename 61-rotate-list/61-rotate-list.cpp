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
    
    int ttlNodes(ListNode* head){
        
        if(head==NULL) return 0;
        
        return 1+ ttlNodes(head->next);
        
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL||k==0||head->next==NULL) return head;
        
        int n = ttlNodes(head);
        if(k%n==0) return head;
        k=k%n;
        
        k= n-k;
        
        
        
        ListNode* curr = head;
        k--;
        while(k>0){
            
            curr=curr->next;
            k--;
            
        }
        
        
        ListNode* l1 = head;
        ListNode* l2 = curr;
        
        ListNode* l3 = curr->next;
        l2->next=NULL;
        curr=l3;
        while(curr!=NULL&&curr->next!=NULL){
            curr=curr->next;
        }
        
        // cout<<curr->val;
        
        ListNode* l4 = curr;
        
        // cout<<l1->val<<endl;
        // cout<<l2->val<<endl;
        // cout<<l3->val<<endl;
        // cout<<l4->val<<endl;
        l4->next = l1;
        
        return l3;
        
       
        
        
        
        
    }
};