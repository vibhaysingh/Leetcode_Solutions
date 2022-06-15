class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, 1e5);
        
        dp[0]=0;
        
        for(int i=0;i<=amount;i++){
            
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0)
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
        
        if(dp[amount]==1e5) return -1;
        
        return dp[amount];
    }
};