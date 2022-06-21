
int dp[100][100][100];


class Solution {
public:
    
//     int solver(int i,int j1,int j2,vector<vector<int>>& grid){
        
//         int n = grid.size();
//         int m = grid[0].size();
        
//         if(i<0 ||j1<0||j2<0||j1>=m||j2>=m||i>=n) return -1e8;
        
        
        
//         if(i==n-1){
            
//             if(j1==j2) return grid[i][j1];
            
//             else return grid[i][j1]+grid[i][j2];
//         }
        
//         if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
//         int mx=-1e8;
//         int val=0;
        
//         for(auto x:{-1,0,1}){
            
//             for(auto y:{-1,0,1}){
                
                 
//         if(j1==j2)
//             val = grid[i][j1];
//         else 
//             val = grid[i][j1]+grid[i][j2];
//                 val  = val + solver(i+1,j1+x,j2+y,grid);
                
//                 mx = max(val,mx);
                
//             }
//         }
        
//         return dp[i][j1][j2]=mx;
        
        
        
        
//     }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        
        int m = grid[0].size();
        int n = grid.size();
        memset(dp,0,sizeof dp);
        for(int j1=0;j1<m;j1++){
            
            for(int j2=0;j2<m;j2++){
                
                 if(j1==j2) 
                     dp[n-1][j1][j2]= grid[n-1][j1];
            
                 else 
                dp[n-1][j1][j2]= grid[n-1][j1]+grid[n-1][j2];
            }
        }
        
        
        for(int i=n-2;i>=0;i--){
            
            for(int j1=0;j1<m;j1++){
                
                for(int j2=0;j2<m;j2++){
                    
                    int mx=-1e8;
                  int val=0;
        
        for(auto x:{-1,0,1}){
            
            for(auto y:{-1,0,1}){
                
                 
                   if(j1==j2)
                        val = grid[i][j1];
                  else 
                     val = grid[i][j1]+grid[i][j2];
                
                if(j1+x>=0 && j1+x<m && j2+y>=0 && j2+y<m){
                 val  = val  + dp[i+1][j1+x][j2+y] ;
                  
                }
                
                
                  mx = max(val,mx);
                
            }
        }
                    
                    dp[i][j1][j2]=mx;
                    
                }
            }
        }
        
        
        return dp[0][0][m-1];
    }
};