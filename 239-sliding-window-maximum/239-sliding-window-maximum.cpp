class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();        
        vector<int>ngr(n);
        stack<int>st;
        ngr[n-1]=n;
        
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--){
            
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                ngr[i]=n;
            }else{
                ngr[i]=st.top();
            }
            st.push(i);
        }
        
        vector<int>ans;
        
        for(int i=0,j=0;i<=n-k;i++){
            
            if(j<i) j=i;
            
            while(ngr[j]<i+k) /// we will move untill the ngr of ith element is out of window
                j = ngr[j];
            
            ans.push_back(nums[j]);
            
        }
        
        return ans;
        
        
    }
};