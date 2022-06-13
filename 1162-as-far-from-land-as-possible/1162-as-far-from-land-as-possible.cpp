class Solution {
public:
    
    bool valid(int x,int y,int n,int m){
        
        if(x<0||y<0||x>=n||y>=m) return false;
        
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1)
                q.push({i,j});
            }
        }
        
        vector<int>dx={-1,1,0,0};
        vector<int>dy={-0,0,-1,1};
        
        int ans=0;
        if(q.size()==n*m) return -1;
        while(!q.empty()){
            
            int l = q.size();
            ans++;
            while(l--){
                
                auto x = q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    
                    int r  = dx[i]+x.first;
                    int c  = dy[i]+x.second;
                    
                    if(valid(r,c,n,m)&&grid[r][c]==0){
                        
                        grid[r][c]=1;
                        q.push({r,c});
                        
                    }
                    
                }
            }
        }
        
        return ans-1;
        
    }
};