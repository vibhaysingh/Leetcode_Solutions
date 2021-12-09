
int dp[205][205];

class Solution {
public:
    
    bool valid(int i, int j, int n, int m)
    {
        if(i<0||i>=n||j<0||j>=m)
            return false;
        return true;
    }
    
    int solver(int i, int j, int n, int m,vector<vector<int>>& grid)
    {
        
        if(!valid(i,j,n,m))
        {
            return INT_MAX;
        }
        
        
        
        if(i==n-1&&j==m-1)
        {
            if(grid[i][j]<0)
            {
                return abs(grid[i][j])+1;
            }
            else
                return 1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int temp = min(solver(i+1,j,n,m,grid),solver(i,j+1,n,m,grid));
        
        
        
 // currently standing at cell (i,j) and to go further temp health is required
        
        if(grid[i][j]>=temp)
            temp=1;
        else
            temp= temp-grid[i][j];
        
        return dp[i][j] = temp;        
           
    }
    
    
    int calculateMinimumHP(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof dp);
        
        // 0    0   0
        // 1    1  -1
        //       1   2
        //       1   2
        return solver(0,0,n,m,grid);
        
    }
};