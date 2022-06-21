int dp[2005][2005];
class Solution {
public:
    
  
    
    bool help( string & s, string &p, int i, int j){
        int n=s.size(),m=p.size();
        
         if(j>=m)
           return  i>=n;
      
        bool check = false;
      
           if(dp[i][j]!=-1)
            return dp[i][j];
      
      
           if(p[j]=='*'){
           
           check = ( (i<n   && help(s,p,i+1,j)) || help(s,p,i,j+1));
            
         }
      else  {
          
           if(i>=n)
            check=false; 
          
          else if(p[j]==s[i] || p[j]=='?')
           check=help(s,p,i+1,j+1);          
      }
      
      return dp[i][j]=check;
    }
    bool isMatch(string s, string p) {
         
        memset(dp,-1, sizeof dp);
      
        return help(s,p,0,0);
   
    }
};