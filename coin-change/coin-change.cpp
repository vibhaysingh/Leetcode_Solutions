int dp[15][10005];
static bool f=false;

class Solution {
public:
    
    
    int solver(vector<int>& coins, int amount,int n)
    {
        
        if(n==0)
            return 100;
        if(amount == 0)
        {
            f=true;
            
            return 0;
        }
        
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        
        int temp;
        
        if(coins[n-1]>amount)
            
            temp = solver(coins,amount,n-1);
        else
        {
            temp = min(1+solver(coins,amount-coins[n-1],n),solver(coins,amount,n-1));
        }
        
        return dp[n][amount] = temp;
        
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        memset(dp,-1,sizeof dp);
        
        int ans = solver(coins,amount,coins.size());
        
        if(ans==100)return -1;
        return ans;
        
    }
};