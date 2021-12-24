
int dp[2005][2005];
int pal[2005][2005];

class Solution {
public:
   
     int isPalindrome(int i,int j,string &s)
    {
         int n =s.size();
         
         if(i>j)
             return 1;
         
         
         if(i==j)
         return pal[i][j]=1;
         
         if(pal[i][j]!=-1)
             return pal[i][j];
         
         
         
         return pal[i][j] = ((s[i]==s[j]) && isPalindrome(i+1,j-1,s));
        
    }
    
    int solver(int i,int j, string &s)
    {
        
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        // string a = s.substr(i,j-i+1);
        if(isPalindrome(i,j,s)==1)
        {
            return dp[i][j]=0;
        }
        
        
        
        
        
        int temp=2500;
        
        for(int k=i;k<j;k++)
        {
            if(isPalindrome(i,k,s)==1){
            int x = 1+ solver(k+1,j,s);
            temp=min(x,temp);
            }
        }
        
        return dp[i][j]=temp;
    }
    
    
    int minCut(string s) {
        
        memset(dp,-1,sizeof dp);
        memset(pal,-1,sizeof pal);
        int n =s.size();
       
        
        return  solver(0,s.size()-1,s);
        
        
        
    }
};