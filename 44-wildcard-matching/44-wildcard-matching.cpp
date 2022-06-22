
class Solution {
public:
    
    
    int solver(int i,int j,string &s,string &p,int &n,int &m,vector<vector<int>>&dp){
        
        
        if(i==n&&j==m) return true;
        
        if(i==n){
            for(int k=j;k<m;k++){
                if(p[k]!='*') return false;
            }
            
            return true;
        }
        
        if(j==m){
            return false;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        if(s[i]==p[j]||p[j]=='?'){
            
            return dp[i][j]=solver(i+1,j+1,s,p,n,m,dp);
        }
        else if(p[j]=='*'){
            
            
            
            return dp[i][j]=(solver(i+1,j,s,p,n,m,dp)||solver(i,j+1,s,p,n,m,dp));
        }
        
        return dp[i][j]=false;
    }
    
    bool isMatch(string s, string p) {
        
        
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        
        return solver(0,0,s,p,n,m,dp);
    }
};