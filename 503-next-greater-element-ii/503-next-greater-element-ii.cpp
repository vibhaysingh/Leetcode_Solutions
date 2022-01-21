class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
//         vector<int>v;
//         v= nums;
//         int n = nums.size();
        
//         for(int i=0;i<n-1;i++){
            
//             v.push_back(nums[i]);
//         }
//         // 1 2 1
//         // 1 2 1 1 2
        
//         stack<pair<int,int>>st;
        
//         int l = v.size();
//         vector<int>ngr(n,-1);
        
//         for(int i=l-1;i>=0;i--){
            
            
//             if(st.empty()){
//                 st.push({v[i],i});
//                 continue;
//             }
            
//             while(!st.empty()&&st.top().first<v[i])
//                 st.pop();
            
//             while(i<n && !st.empty()&&st.top().second>=(i+n))
//                 st.pop();
            
//             if(!st.empty()&&i<n){
                
//                 ngr[i] = st.top().first;
               
//             }else if(st.empty()&&i<n){
                
//                 ngr[i] = -1;
//             }
                     
//             st.push({v[i],i});
            
            
//         }
        
        
        int idx = max_element(nums.begin(),nums.end())-nums.begin();
        
        int j = idx-1;
        int n = nums.size();
        if(j<0)j=n-1;
        // int n = nums.size();
        
        vector<int>ngr(n,-1);
        ngr[idx]=-1;
        
        stack<int>st;
        
        st.push(nums[idx]);
        
        while(j != idx){
            
            
            while(!st.empty()&&st.top()<=nums[j])
              st.pop();
            
            if(st.empty()){
                ngr[j]=-1;
            }
            else
            {
                ngr[j] = st.top();
            }
            
            st.push(nums[j]);
            j--;
            
            if(j<0)j=n-1;
            
        }
        
        
        return ngr;
        
    }
};



   // [1,2,3,4,3,1,2,3,4]
   
   
