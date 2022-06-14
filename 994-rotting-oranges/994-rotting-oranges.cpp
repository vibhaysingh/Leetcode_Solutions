class Solution {
public:
    
    bool valid(int x,int y,int n,int m){
        
        if(x<0||y<0||x>=n||y>=m) return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        
        int fresh=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==2){ q.push({i,j});}
                else if(grid[i][j]==1) fresh++;
            }
        }
        
        int ans=0;
        
        vector<int>dx={0,0,1,-1};
        vector<int>dy={-1,1,0,0};
        
        // cout<<fresh<<endl;
        
        if(fresh==0) return 0;
        
        while(!q.empty()){
            
            int l = q.size();
            // cout<<l<<endl;
            
            while(l--){
                
                auto [x,y]=q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    
                    int r = dx[i]+x;
                    int c = dy[i]+y;
                    
                    if(valid(r,c,n,m) && grid[r][c]==1){
                        
                        q.push({r,c});
                        grid[r][c]=2;
                        fresh--;
                    }
                }
            }
            ans++;
        }
        
        // cout<<fresh<<endl;
        
        if(fresh>0) return -1;
        
        return ans-1;
        
    }
};