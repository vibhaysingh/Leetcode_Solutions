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
        
        if(head==NULL||head->next==NULL) return head;
        
        ListNode* dummy = new ListNode(INT_MIN);
        
        dummy->next = head;
        ListNode* curr = head->next;
        ListNode* prevCurr = head;
        ListNode* currNext = NULL;
        
        
        while(curr!=NULL){
            
            
            
            currNext = curr->next; // store the next node
            ListNode* j = dummy->next; // head
            ListNode* prevj=dummy; // dummy node ko point kr rha hai
            bool f= false;
            
            
            while(j!=curr){ // jb tk j curr ke barabar n pahuch jaye
                
                
                if(j->val<=curr->val){ // value kam hai to j ko badhate rho
                    
                    prevj = j; // prev store kiya 
                    j=j->next; // j ko badhaya
                    continue;
                }
                
                // yha pr j->val jyada hai curr->val se
                
                
        // cout<<curr->val << j->val <<prevj->val <<prevCurr->val<<endl;
                
                f=true;
                curr->next=j; // step 1 done
                prevj->next=curr; // step 2 done
                prevCurr->next = currNext; //step 3 done
                
                break;
            }
            
            if(f==false)
                prevCurr = curr;
            curr = currNext;
            
        }
        
        return dummy->next;
        
    }
};