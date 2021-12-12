int dp[1005][1005];
       const int mod =1e9+7;

class Solution {
public:
    
    int solver(int diceused,int f,int ttldice,int target,int currsum)
    {
        
        
        if(diceused==ttldice&&currsum==target)
        {
            return 1;
        }
        
        if(dp[diceused][currsum]!=-1)
            return dp[diceused][currsum];
        
        int temp=0;
        
        
        
        for(int i=1;i<=f;i++)
        {
            if(currsum+i<=target)
            {
                temp= (temp%mod+solver(diceused+1,f,ttldice,target,currsum+i)%mod)%mod;
            }
        }
        
        return dp[diceused][currsum]=temp%mod;
        
    }
    
    int numRollsToTarget(int d, int f, int target) {
        
        memset(dp,-1,sizeof dp);
        return solver(0,f,d,target,0)%mod;
    }
};