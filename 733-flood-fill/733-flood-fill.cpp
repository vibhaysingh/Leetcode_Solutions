class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& mat, int newColor,int prevColor){
        
        int n = mat.size();
        int m = mat[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || mat[i][j]==newColor || mat[i][j]!=prevColor) return;
        
        mat[i][j] = newColor;
        
        dfs(i-1,j,mat,newColor,prevColor);
         dfs(i,j-1,mat,newColor,prevColor);
         dfs(i+1,j,mat,newColor,prevColor);
         dfs(i,j+1,mat,newColor,prevColor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int newColor) {
        
        
        dfs(sr,sc,mat,newColor,mat[sr][sc]);
        
        return mat;
    }
};