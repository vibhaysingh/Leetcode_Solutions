class Solution {
public:
    int distinctSubseqII(string s) {
        
        int n = s.size();
        
        int dp[n+1];
        
        int m = 1e9+7;
        
        dp[0]=1;
        
        map<char,int>mp;
        
        for(int i=1;i<=n;i++){
            
            
            if(mp.find(s[i-1])!= mp.end()){
                
                // cout<<i-1<<" i"<<endl;
                
                dp[i] = (2*dp[i-1]%m);
                
                dp[i] = (dp[i]%m - dp[mp[s[i-1]]] +m )%m;
                
                // cout<<mp[s[i-1]]<<endl;
            }
            else{
                dp[i] = (2*dp[i-1]%m);
            }
            
            mp[s[i-1]]=i-1;
        }
        
        return dp[n]-1;
        
    }
};