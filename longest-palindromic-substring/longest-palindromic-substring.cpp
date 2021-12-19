class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof dp);
        int l=0,e=0;
        
        for(int gap=0;gap<n;gap++)
        {
            
            int i, j;
            
            for(i=0,j=gap;i<n&&j<n;i++,j++)
            {
                if(gap==0)
                {
                    dp[i][j]=1;
                }
                else if(gap==1)
                {
                    dp[i][j]=(s[i]==s[j]);
                }
                else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                
                if(dp[i][j])
                {
                    l=i;
                    e=j;
                }
            }
                        
        }
        
        string ans="";
        
        for(int i=l;i<=e;i++)
        {
            ans+=s[i];
        }
        return ans;
        
    }
};