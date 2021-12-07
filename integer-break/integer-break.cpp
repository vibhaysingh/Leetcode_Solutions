
// int dp[60];

class Solution {
public:    
//    int solver(int n)
//     {
//         if(n==1)
//             return 1;
        
//         if(dp[n]!=-1)
//             return dp[n];
//         int i,ans=n;
        
//         for(i=1;i<n;i++)
//         {
//             ans = max(ans,solver(i)*solver(n-i));
//         }
//        return dp[n]=ans;
//     }
    
    int integerBreak(int n) {
        
        // n ---> k parts
        // max product
        if(n<=3)
            return n-1;
        
         int dp[n+1];
        
        memset(dp,-1,sizeof dp);
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=4;i<=n;i++)
        {
            dp[i]=i;
            for(int j=1;j<i;j++)
            {
               dp[i] = max(dp[i],dp[j]*dp[i-j]);
            }
           
        }
        
        // memset(dp,-1,sizeof dp);   
        return dp[n];
        
        
    }
};