
int dp[105][105];
class Solution {
public:
    
     bool isValid(int i,int j,int n, int m,vector<vector<int>>& grid)
    {
        if(i<0||i>=n||j<0||j>=m||grid[i][j]==1)
            return false;
        return true;
    }
    
    int solver(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        
        if(!isValid(i,j,n,m,grid))
        {
            return 0;
        }
        
        if(i==n-1&&j==m-1)
        {
            // cout<<"here";
            return 1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int temp = solver(i+1,j,n,m,grid)+solver(i,j+1,n,m,grid);
        
        return dp[i][j]=temp;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,0,n,m,grid);
        
    }
};