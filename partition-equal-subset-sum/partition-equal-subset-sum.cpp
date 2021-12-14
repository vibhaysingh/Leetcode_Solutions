
int dp[205][20005];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum%2) return false;
                
           memset(dp,-1,sizeof dp);
        
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
 
      for (int i = 1; i <= sum; i++)
            dp[0][i] = 0;
            
        
        for (int i = 1; i <= n; i++) 
        {
        for (int j = 1; j <= sum; j++) 
        {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];
 
            // If i'th element is included
            if (nums[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - nums[i - 1]];
        }
       }
        
        
        return dp[n][sum/2];
    }
};