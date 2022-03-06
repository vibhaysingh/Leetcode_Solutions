class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        set<long long >st;
        
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        
        vector<long long int>temp;
        
        long long sum = 0;
        
        for(auto k:st){
            
            temp.push_back(k);
           
        }
        
        // cout<<sum<<endl;
        
        long long low =k,high=1e9,mid,ans=1e10;
        
        while(low<=high){
            
            
            mid = (low+high)/2;
            
            int cnt = upper_bound(temp.begin(),temp.end(),mid)-temp.begin();
            
            // cout<<cnt<<endl;
            
            if(mid-cnt>=k){
                
                ans=min(ans,mid);
                
                high=mid-1;
            }
            else{
              
                low=mid+1;
            }
       
            
            
            
        }
        
        // cout<<ans<<endl;
        
        
        long long x = (ans*(ans+1))/2;

        
       for(auto k:st){
           if(k<=ans){
               sum+=k;
           }
           else{
               break;
           }
       }
        
        return x-sum;
        
        
    }
};