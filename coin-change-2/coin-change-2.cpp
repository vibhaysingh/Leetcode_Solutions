int dp[305][5005];
class Solution {
public:
    
    int solver(int amount, vector<int>& coins,int l)
    {
        if(l==0)
            return 0;
        if(amount==0)
        {
            return 1;
        }
        
        if(dp[l][amount]!=-1)
        {
            return dp[l][amount];
        }
        
        int temp;
        
        if(coins[l-1]>amount)
        {
            temp = solver(amount,coins,l-1);
        }
        else
        {
            temp=solver(amount-coins[l-1],coins,l)+solver(amount,coins,l-1);
        }
        
        return dp[l][amount]=temp;
    }
    int change(int amount, vector<int>& coins) {
        
        memset(dp,-1,sizeof dp);
       
        return solver(amount,coins,coins.size());
    }
};