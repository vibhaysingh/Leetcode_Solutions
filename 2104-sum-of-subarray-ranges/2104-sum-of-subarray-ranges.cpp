class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        
        
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
            
            ans = ans+  (nums[i]*l*r);
        }
        
        
        // int n = nums.size();
        
         left.assign(n,-1),right.assign(n,n);
         while(!st.empty()) st.pop();

        // stack<int>st;
        
        for(int i=0;i<n;i++){
            
            if(st.empty()){
                st.push(i);
                continue;
            }
                        
            while(! st.empty() && nums[st.top()] <nums[i]) st.pop();
            
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
            
             while(!st.empty() && nums[st.top()] <=nums[i]) st.pop();
            
             if(!st.empty()) 
            right[i] = st.top();
            
            st.push(i);            
            
        }
        
//         for(auto k:left)cout<<k<<" ";
//         cout<<endl;
        
//         for(auto k:right)cout<<k<<" ";
//         cout<<endl;
        
        long long int ans1 = 0;
        
        for(int i=0;i<n;i++){
            
          long long  int l = (right[i]-i);
           long long  int r = (i-left[i]);
            
            ans1 = (ans1 +(nums[i]*l*r));
        }
        
        return ans1-ans;
        
    }
};