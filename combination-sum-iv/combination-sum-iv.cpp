unsigned int dp[205][1005];

class Solution {
public:
    
    
    int solver(vector<int>& coins, int amount,int idx)
    {
        if(idx>=coins.size())
            return 0;
        if(amount==0)
        {
            return 1;
        }
        
        if(dp[idx][amount]!=-1)
        {
            return dp[idx][amount];
        }
        
        int temp=0;
        
        for(int i=idx;i<coins.size();i++)
        {
            if(coins[i]<=amount)
            {
                temp+=solver(coins,amount-coins[i],idx)+solver(coins,amount,idx-1);
            }
            else
            {
                temp+=solver(coins,amount,idx-1);
            }
        }
        
        return dp[idx][amount]=temp;
    }
    
    
    int combinationSum4(vector<int>& coins, int amount) {
        
        memset(dp,-1,sizeof dp);        
        // vector<int>dp(amount+1,0);
        
//         int l = coins.size();
        
//         dp[0]=1;
        
//          for(int i=1;i<amount+1;i++)
//          {
//              for(int j=0;j<l;j++)
//              {
//                  if(coins[j]<=i)
//                  {
//                      dp[i]+=dp[i-coins[j]];
//                  }
//              }
//          }
        
        
//         return dp[amount];
        
        return solver(coins,amount,0);
    }
};