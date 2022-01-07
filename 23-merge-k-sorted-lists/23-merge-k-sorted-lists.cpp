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
    
     ListNode* mergeTwoLists ( ListNode* leftList,ListNode* rightList){
         
         if(leftList==NULL){
             return rightList;
         }
         
         if(rightList==NULL){
             return leftList;
         }
         
         if(leftList->val<=rightList->val){
             
             leftList->next = mergeTwoLists(leftList->next,rightList);
             
             return leftList;
             
         }else{
             
             rightList->next = mergeTwoLists(leftList,rightList->next);
             
             return rightList;
         }
         
         return NULL;
     }
    
    ListNode* solver(vector<ListNode*>& lists,int start,int end){
        
        if(start>end) return NULL;
        
        if(start==end) return lists[start];
        
        int mid = (start+end)/2;
        
        ListNode* leftList = solver(lists,start,mid);
        ListNode* rightList = solver(lists,mid+1,end);
        
        return mergeTwoLists(leftList,rightList);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int start = 0;
        int end = lists.size()-1;
        
        return solver(lists,start,end);
        
    }
};