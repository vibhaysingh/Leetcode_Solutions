class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        
        int n = nums.size();
        
        int dp[n+1];
        memset(dp,0,sizeof dp);
        int ans=0;
        
        for(int i=2;i<n;i++){
            
            if(nums[i-2]-nums[i-1]==nums[i-1]-nums[i]){
                
                // cout<<i<<endl;
                dp[i]=1+dp[i-1];
                ans+=dp[i];
            }
        }
        
        return ans;
    }
};