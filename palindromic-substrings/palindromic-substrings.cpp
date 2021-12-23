class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        
        int dp[n][n];
        memset(dp,0,sizeof dp);
        
        int ans =0;
        
        for(int gap = 0 ;gap<n;gap++)
        {
            
            for(int start = 0 ,end=gap;start<n && end<n;start++,end++)
            {
                
                if(gap==0)
                {
                    dp[start][end]=1;
                }
                else if(gap==1)
                {
                     dp[start][end]=(s[start]==s[end]);
                }
                else
                {
                    if(s[start]==s[end]&&dp[start+1][end-1]==1)
                    {
                        dp[start][end]=1;
                    }
                    else
                    {
                        dp[start][end]=0;
                    }
                        
                }
                
                ans+=(dp[start][end]==1);
                
            }
            
        }
        
        return ans;
    }
};