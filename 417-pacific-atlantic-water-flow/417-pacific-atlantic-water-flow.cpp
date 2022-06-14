class Solution {
public:
    
    
    void dfs(int i,int j,vector<vector<int>>& h,vector<vector<bool>>&vis){
        int n = h.size();
        int m = h[0].size();
        
        if(i<0||j<0||i>=n||j>=m||vis[i][j]) return;
            
        int d = h[i][j];
        
        vis[i][j]=1;
        
        if(i-1>=0 && h[i-1][j]>=d ){
            
            dfs(i-1,j,h,vis);
        }
        
         if(i+1<n && h[i+1][j]>=d ){
            
            dfs(i+1,j,h,vis);
        }
        
         if(j-1>=0 && h[i][j-1]>=d ){
            
            dfs(i,j-1,h,vis);
        }
        
         if(j+1<m && h[i][j+1]>=d ){
            
            dfs(i,j+1,h,vis);
        }
        
           
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        
        int n = h.size();
        int m = h[0].size();
        
        
        vector<vector<bool>>p(n,vector<bool>(m,false));
        vector<vector<bool>>a(n,vector<bool>(m,false));
        
        
        for(int i=0;i<n;i++){
            
            dfs(i,0,h,p);
            dfs(i,m-1,h,a);
        }
        
        for(int i=0;i<m;i++){
            
            dfs(0,i,h,p);
            dfs(n-1,i,h,a);
        }
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(p[i][j]&&a[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
        
        
    }
};