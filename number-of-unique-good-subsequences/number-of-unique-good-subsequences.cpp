class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        
        int n = s.size();
        
        int i=0;
        while(i<n&&s[i]=='0')
            i++;
        if(i==n) return 1;
        bool haveZero=false;
        if(i>0)
            haveZero=true;
        int dp[n];
        memset(dp,0,sizeof dp);
        dp[i]=1;
        
        int prevOneidx=-1;
        int prevZeroidx=-1;
        int mod =1e9+7;
        for(int j=i+1;j<n;j++)
        {
            dp[j]=(2*dp[j-1]%mod)%mod;
               
                if(s[j]=='0')
                {
                    haveZero=true;
                    if(prevZeroidx!=-1)
                    dp[j]=(dp[j]%mod-dp[prevZeroidx-1]+mod)%mod;
                    prevZeroidx=j;
                }
              else if(s[j]=='1')
                {
                    if(prevOneidx!=-1)
                    dp[j]=(dp[j]%mod-dp[prevOneidx-1]+mod)%mod;
                    prevOneidx=j;
                }
        }
        if(haveZero)
        return dp[n-1]+1;
        else
            return dp[n-1];
        
        
    }
};