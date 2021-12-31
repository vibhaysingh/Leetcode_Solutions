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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL) return NULL;
        
        if(head->next==NULL)
            return head;
        
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* evenHead = even;
        ListNode* oddHead = odd;
        ListNode* curr = head;
        bool oddIdx = true;
         // cout<<oddHead<<endl;
        while(curr!=NULL){
            
            // cout<<curr->val<<endl;
            
            if(oddIdx){
                
                odd->next=curr;
                odd=curr;
                oddIdx=false;
                
            }else{
                even->next=curr;
                even=curr;
                oddIdx=true;
                
            }
            curr=curr->next;
        }
        
        cout<<odd->next<<endl;
        cout<<evenHead->next->val<<endl;
        
        odd->next = evenHead->next;
        cout<<head->val<<endl;
        cout<<oddHead->next->val<<endl;
        head=oddHead->next;
        even->next=NULL;
        return head;
        
        
        
    }
};