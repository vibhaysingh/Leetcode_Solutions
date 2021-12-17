int dp[1005][1005];
class Solution {
public:
    
    int solver(int i,int j, string &s1,string &s2)
    {
        
        int n =s1.size();
        int m = s2.size();
        
        if(i>=n||j>=m)
            return 0;
        
        if(i==n&&j==m)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        
        int ans=0;
        
        if(s1[i]==s2[j])
        {
            return dp[i][j] = (int)s1[i]+solver(i+1,j+1,s1,s2);
        }
        else
        {
            ans = max({0,solver(i+1,j,s1,s2),solver(i,j+1,s1,s2)});
        }
        
        return dp[i][j]=ans;
        
        
    }
    
    int minimumDeleteSum(string s1, string s2) {
        
        int ttl =0;
        
        for(char c:s1)
        {
            ttl+=(int)c;
        }
        
         for(char c:s2)
        {
            ttl+=(int)c;
        }
        
        memset(dp,-1,sizeof dp);
        
        // char c ='s';
        // cout<<ttl<<endl;
        
        return ttl-2*solver(0,0,s1,s2);
        
        
    }
};