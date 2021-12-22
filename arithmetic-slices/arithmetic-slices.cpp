class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        int dp[n];
        memset(dp,0,sizeof dp);
        
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                dp[i]=dp[i-1]+1;
            
        }
        
        return accumulate(dp,dp+n,0);
        
    }
};