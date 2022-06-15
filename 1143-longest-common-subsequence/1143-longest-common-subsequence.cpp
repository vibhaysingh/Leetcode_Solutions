
int dp[1005][1005];
class Solution {
public:
    
    int solver(string &a,string &b,int n,int m){
        
        if(n==0||m==0) return 0;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        int temp;
        
        if(a[n-1]==b[m-1]){
            
            temp= 1+solver(a,b,n-1,m-1);
        }
        
        else{
            temp= max(solver(a,b,n-1,m),solver(a,b,n,m-1));
        }
        
        return dp[n][m]=temp;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        
        int n = text1.size();
        int m = text2.size();
        
        memset(dp,-1,sizeof dp);
        
        return solver(text1,text2,n,m);
    }
};