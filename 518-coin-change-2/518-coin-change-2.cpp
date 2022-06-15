int dp[5005];
class Solution {
public:
    
//     int solver(int amount, vector<int>& coins,int l)
//     {
//         if(l==0)
//             return 0;
//         if(amount==0)
//         {
//             return 1;
//         }
        
//         if(dp[l][amount]!=-1)
//         {
//             return dp[l][amount];
//         }
        
//         int temp;
        
//         if(coins[l-1]>amount)
//         {
//             temp = solver(amount,coins,l-1);
//         }
//         else
//         {
//             temp=solver(amount-coins[l-1],coins,l)+solver(amount,coins,l-1);
//         }
        
//         return dp[l][amount]=temp;
//     }
    int change(int amount, vector<int>& coins) {
        
        memset(dp,0,sizeof dp);        
        // vector<int>dp(amount+1,0);
        int l = coins.size();
        
        
        dp[0]=1;
        
        for(int i=0;i<l;i++){
            
            for(int j=coins[i];j<=amount;j++){
                
                dp[j] = dp[j] + dp[j-coins[i]];
            }
        }
        
        
        
        return dp[amount];
        
        
       
        
    }
};