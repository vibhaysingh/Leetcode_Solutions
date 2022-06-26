class Solution {
public:
    
    int dp[1005][3];
    
    int solver(int k,int n){
        
        if(n<=1) return n;
        
        if(k==1) return n;
        
        int mn = INT_MAX;
        
        if(dp[n][k]!=-1) return dp[n][k];
        
        for(int i=1;i<=n;i++){
            
            int d = solver(k-1,i-1);
            int u = solver(k,n-i);
            
            mn = min(mn,1+max(d,u));
            
        }
        
        return dp[n][k]=mn;
    }
    
    int twoEggDrop(int n) {
        
        memset(dp,-1,sizeof dp);
        
        return solver(2,n);
    }
};