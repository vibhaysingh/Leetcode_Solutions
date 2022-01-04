
int dp[105][105];

class Solution {
public:
    
    bool isValid(int i,int j,int n, int m)
    {
        if(i<0||i>=n||j<0||j>=m)
            return false;
        return true;
    }
    
    int solver(int i,int j,int n,int m)
    {
        
        if(!isValid(i,j,n,m))
        {
            return 0;
        }
        
        if(i==n-1&&j==m-1)
        {
            return 1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int temp = solver(i+1,j,n,m)+solver(i,j+1,n,m);
        
        return dp[i][j]=temp;
    }
    
    int uniquePaths(int n, int m) {
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,0,n,m);
        
        
//         for(int i=0;i<m;i++)
//         {
//             dp[n-1][i]=1;
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             dp[i][m-1]=1;
//         }
        
//         for(int i=n-2;i>=0;i--)
//         {
//             for(int j=m-2;j>=0;j--)
//             {
//                 dp[i][j]=(dp[i+1][j]+dp[i][j+1]);
//             }
//         }
                
//         return dp[0][0];
        
        
    }
};