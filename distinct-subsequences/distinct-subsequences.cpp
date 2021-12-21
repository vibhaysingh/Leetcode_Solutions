int dp[1005][1005];

class Solution {
public:
    
    int solver(int i,int j,string &s, string &t)
    {
        int n =s.size();
        int m =t.size();
        
        if(j==m) return 1;
        
        if(i==n) return 0;
        
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = 0;
               
         if(s[i]==t[j])
         {
// found a match then we have two option take that and move forward or skip the character and move
            ans += solver(i+1,j+1,s,t)+solver(i+1,j,s,t);
         }
        else
        {
            // if there is no match then we have only one option that is move forward
            ans += solver(i+1,j,s,t);
        }
        
        return dp[i][j]=ans;
    }
    
    int numDistinct(string s, string t) {
       
        memset(dp,-1,sizeof dp);
        return solver(0,0,s,t);
    }
};