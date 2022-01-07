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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto it =[] (ListNode*a,ListNode*b){
            
            if(a->val>b->val)
                return true;
            return false;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(it)> pq(it);
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        for(auto k:lists){
            
            if(k!=NULL)
            pq.push(k);
        }
        
        while(!pq.empty()){
            
            auto k = pq.top();
            pq.pop();
            
            curr->next = k;
            curr = k;
            
            if(k!=NULL&&k->next!=NULL){
                pq.push(k->next);
            }
        }
        
        return head->next;
    }
};