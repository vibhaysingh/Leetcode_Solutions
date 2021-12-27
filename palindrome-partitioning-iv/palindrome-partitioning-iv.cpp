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
    
    bool solver(string &s)
    {
        
      int n = s.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if(isPalindrome(0,i,s)&&isPalindrome(i+1,j,s)&&isPalindrome(j+1,n-1,s))
                    return true;
                
            }
        }
        
        return false;
        
    }
    
    bool checkPartitioning(string s) {
         memset(pal,-1,sizeof pal);
        
        return solver(s);
        
    }
};