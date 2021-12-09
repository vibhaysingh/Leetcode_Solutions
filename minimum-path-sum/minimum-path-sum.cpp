int dp[205][205];

class Solution {
public:
    
    bool valid(int i,int j,int n, int m)
    {
        if(i<0||i>=n||j<0||j>=m)
            return false;
        return true;
    }
    
    int solver(int i, int j, int n ,int m,vector<vector<int>>& grid)
    {
        if(!valid(i,j,n,m))
            return INT_MAX;
        if(i==n-1&&j==m-1)
        {
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int temp=INT_MAX;
        temp = grid[i][j]+min(solver(i+1,j,n,m,grid),solver(i,j+1,n,m,grid));
        
        return dp[i][j]=temp;
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,0,n,m,grid);
        
    }
};