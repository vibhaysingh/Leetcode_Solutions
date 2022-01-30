int dp[21];

class Solution {
public:
    
    int solver(int n){
        
        if(n<=1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
         int ans = 0;
        
        for(int i=1;i<=n;i++){
            
            ans+= solver(i-1)*solver(n-i);
        }
        
        return dp[n]=ans;
    }
    
    int numTrees(int n) {
        
        memset(dp,-1,sizeof dp);
        
        return solver(n);
    }
};