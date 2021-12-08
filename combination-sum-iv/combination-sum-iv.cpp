unsigned int dp[1005];

class Solution {
public:
    int combinationSum4(vector<int>& coins, int amount) {
        
        memset(dp,0,sizeof dp);        
        // vector<int>dp(amount+1,0);
        int l = coins.size();
        
        dp[0]=1;
        
         for(int i=1;i<amount+1;i++)
         {
             for(int j=0;j<l;j++)
             {
                 if(coins[j]<=i)
                 {
                     dp[i]+=dp[i-coins[j]];
                 }
             }
         }
        
        
        return dp[amount];
    }
};