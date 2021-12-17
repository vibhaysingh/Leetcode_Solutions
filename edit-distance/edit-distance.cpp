
int dp[505][505];

class Solution {
public:
    
    int solver(int i,int j,string s1,string s2)
    {
        int n1=s1.size();
        int n2=s2.size();
        
        if(i>n1||j>n2)
            return INT_MAX;
        if(i==n1&&j==n2)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];            
        
        int x= INT_MAX;
        if(s1[i]==s2[j])
            return dp[i][j]= solver(i+1,j+1,s1,s2);
        else
        {
            x= 1+min({x,solver(i+1,j+1,s1,s2),solver(i,j+1,s1,s2),solver(i+1,j,s1,s2)});
        }
        
        return dp[i][j]=x;
    }
    
    int minDistance(string word1, string word2) {
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,0,word1,word2);
        
    }
};