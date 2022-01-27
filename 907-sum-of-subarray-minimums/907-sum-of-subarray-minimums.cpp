class Solution {
public:
    
    int m = 1e9+7;
    
    int sumSubarrayMins(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> left(n,-1),right(n,n);

        stack<int>st;
        
        for(int i=0;i<n;i++){
            
            if(st.empty()){
                st.push(i);
                continue;
            }
                        
            while(! st.empty() && nums[st.top()] >nums[i]) st.pop();
            
            if(!st.empty())
            left[i] = st.top(); 
            st.push(i);            
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            
             if(st.empty()){
                st.push(i);
                continue;
            }
            
             while(!st.empty() && nums[st.top()] >=nums[i]) st.pop();
            
             if(!st.empty()) 
            right[i] = st.top();
            
            st.push(i);            
            
        }
        
//         for(auto k:left)cout<<k<<" ";
//         cout<<endl;
        
//         for(auto k:right)cout<<k<<" ";
//         cout<<endl;
        
        long long int ans = 0;
        
        for(int i=0;i<n;i++){
            
          long long  int l = (right[i]-i);
           long long  int r = (i-left[i]);
            
            ans = (ans%m +  (nums[i]%m*l%m*r%m)%m)%m;
        }
        
        return ans;
        
    }
};