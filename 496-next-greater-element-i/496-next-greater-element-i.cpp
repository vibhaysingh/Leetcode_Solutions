class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int a[10005];
        
        memset(a,-1,sizeof a);
        
        stack<int>st;
        
        int n  = nums2.size();
        vector<int>ngr(n,-1);
        
        // unordered_map<int,int>mp;
        
        for(int i=n-1;i>=0;i--){
            
            // mp[nums2[i]]=i;
            if(st.empty()){
                st.push(nums2[i]);
                continue;
            }
            
            while(!st.empty()&&st.top()<nums2[i])
                st.pop();
            
            if(!st.empty()){
                ngr[i]=st.top();
            }else{
                ngr[i]=-1;
            }
            
            a[nums2[i]]=ngr[i];
            
            st.push(nums2[i]);
            
            
        }
        
        vector<int>ans;
        
        for(int i=0;i<nums1.size();i++){
            
            // int idx = mp[nums1[i]];
            ans.push_back(a[nums1[i]]);
        }
        
        
        
        return ans;
    }
};