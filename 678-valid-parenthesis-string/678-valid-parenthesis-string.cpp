class Solution {
public:
    
    int dp[105][105][105];
    
    bool solver(int idx,int open,int close,string &s){
        
        if(idx==s.size()){
            return (open==close);
        }
        
        if(close >open) return false;
        
        if(dp[idx][open][close]!=-1) return dp[idx][open][close];
        
        bool f= false;
        
        if(s[idx]=='('){
            
            f= f|(solver(idx+1,open+1,close,s));
            
        }
        else if(s[idx]==')'){
            f= f|(solver(idx+1,open,close+1,s));
        }
        else if(s[idx]=='*'){
             f= f|(solver(idx+1,open+1,close,s));
              f= f|(solver(idx+1,open,close+1,s));
              f= f|(solver(idx+1,open,close,s));
        }
        
        return dp[idx][open][close]=f;
    }
    
    bool checkValidString(string s) {
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,0,0,s);
    }
};