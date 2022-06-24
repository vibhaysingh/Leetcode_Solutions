
int dp[55][55][55];

class Solution {
public:
    
    // r1+c1 == r2+c2 (always)
    // c2 = (r1+c1)-r2;
    
//     int solver(int r1,int c1,int r2,vector<vector<int>>&grid){
        
//         int n = grid.size();
//         int c2 = (r1+c1)-r2;

//          if(r1>=n||r2>=n ||c1>=n||c2>=n || grid[r1][c1]==-1||grid[r2][c2]==-1) return INT_MIN;
        
//         if(r1==n-1 && c1==n-1) return grid[r1][c1];
        
//           if( dp[r1][c1][r2]!= -1) 
//              return  dp[r1][c1][r2];
        
//         int ans=0;
        
//         if(r1==r2&&c1==c2){
//             ans=grid[r1][c1];
//         }
//         else{
//             ans =grid[r1][c1]+grid[r2][c2];
//         }
        
        
        
      
        
//         int br = solver(r1,c1+1,r2,grid);
//         int bd = solver(r1+1,c1,r2+1,grid);
//         int orod = solver(r1,c1+1,r2+1,grid);
//         int odor = solver(r1+1,c1,r2,grid);
        
//         ans  = ans+  max({br,bd,orod,odor});
        
//         return dp[r1][c1][r2]=ans;
//     }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
       
        
        for(int i=0;i<55;i++){
            for(int j=0;j<55;j++){
                for(int k=0;k<55;k++){
                    
                    dp[i][j][k]=INT_MIN;
                }
            }
        }
        
        for(int r1=n-1;r1>=0;r1--){
            
            for(int c1=n-1;c1>=0;c1--){
                
                for(int r2=n-1;r2>=0;r2--){
                    
                    int c2 = (r1+c1)-r2;
                    
                    if(c1<0||c2<0||r1<0||r2<0||r1>=n||r2>=n ||c1>=n||c2>=n || grid[r1][c1]==-1||grid[r2][c2]==-1){
                       
                        continue;
                    }
                   
                    
                     if(r1==n-1 && c1==n-1) {
                         dp[r1][c1][r2]= grid[r1][c1];
                         continue;}
                      
                    int ans=0;
        
        if(r1==r2&&c1==c2){
            ans=grid[r1][c1];
        }
        else{
            ans =grid[r1][c1]+grid[r2][c2];
        }
        
        
        
      
        
        int br  =dp[r1][c1+1][r2];
        int bd = dp[r1+1][c1][r2+1];
        int orod = dp[r1][c1+1][r2+1];
        int odor = dp[r1+1][c1][r2];
        
        ans  = ans+  max({br,bd,orod,odor});
        
         dp[r1][c1][r2]=ans;
                }
            }
        }
        
        
        return max(0,dp[0][0][0]);
    }
};