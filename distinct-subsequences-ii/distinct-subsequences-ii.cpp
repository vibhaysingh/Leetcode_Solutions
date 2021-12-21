class Solution {
public:
    int distinctSubseqII(string s) {
        
        int n =s.size();
        int mod=1e9+7;
        int dp[n+1];
        dp[0]=1;
        
        map<char,int>mp;
        
        for(int i=0;i<n;i++)
        {
            
            if(mp.find(s[i])!=mp.end())
            {
                dp[i+1]=(2%mod*dp[i]%mod)%mod;
                dp[i+1]=(dp[i+1]-dp[mp[s[i]]]+mod)%mod;
            }
            else
            {
                dp[i+1]=(2%mod*dp[i]%mod)%mod;
            }
            mp[s[i]]=i;
            
        }
        
        return dp[n]-1;
    }
};