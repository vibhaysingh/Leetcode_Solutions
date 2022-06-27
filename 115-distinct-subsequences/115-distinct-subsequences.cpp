class Solution {
public:
    
    int dp[1005][1005];
    int solver(int i,int j,string &s,string &t){
        
        int n = s.size();
        int m = t.size();
         if(j==m){
            return 1;
        }
        if(i>=n) return 0;
        
       
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int temp=0;
        
       if(s[i]==t[j]){
           temp+=solver(i+1,j+1,s,t);
       }
        temp+=solver(i+1,j,s,t);
        
        return dp[i][j]=temp;
    }
    
    int numDistinct(string s, string t) {
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,0,s,t);
    }
};