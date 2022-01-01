class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
    
        int  prev_sum=nums[0];
        int ans=nums[0];
        
        for(int i=1;i<n;i++){
            
            if(prev_sum>=0){
                prev_sum+=nums[i];
                ans=max(ans,prev_sum);
            }
            else{
                // cout<<i<<endl;
                prev_sum= nums[i];
                ans=max(ans,prev_sum);
            }
            
        }
        
        // kadane Algorithm
        return ans;
        
        
    }
};