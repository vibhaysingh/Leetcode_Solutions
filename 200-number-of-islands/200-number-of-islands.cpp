class Solution {
public:
    
    void dfs(int i,int j, vector<vector<char>>& mat){
        
        int n = mat.size();
        int m = mat[0].size();
        
        if(i<0 ||i>=n||j<0||j>=m || mat[i][j]=='0') return;
        
        mat[i][j]='0';
        
        dfs(i-1,j,mat);
        dfs(i+1,j,mat);
        dfs(i,j-1,mat);
        dfs(i,j+1,mat);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1'){
                    
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};