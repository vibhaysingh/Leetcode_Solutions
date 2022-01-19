
int dp[25][35];

class Solution {
public:
    
    bool solver(int n,string &s, int m ,string &p){
        
        
        if(n<=-1 && m<=-1) 
            return true; 
        
        if(n==-1&&p[m]=='*'){
            
            return solver(n,s,m-2,p);
        }
        
        if(n==-1||m==-1) return false;
        
        
        
        
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        bool temp = false;
        
        if(s[n]==p[m]){         
            temp =  solver(n-1,s,m-1,p);
        }
        else if(p[m]=='.'){ 
            temp= solver(n-1,s,m-1,p);
        }
        else if(p[m]=='*'){ 
            
            if(p[m-1]==s[n]||p[m-1]=='.'){
                
                temp  =  solver(n-1,s,m,p)||solver(n,s,m-2,p);
            }
            else
                temp = solver(n,s,m-2,p);
        }
        
        return dp[n][m] = temp;
        
    }
    
    bool isMatch(string s, string p) {
        
        
        memset(dp,-1,sizeof dp);
        
        return solver(s.size()-1,s,p.size()-1,p);
        
    }
};