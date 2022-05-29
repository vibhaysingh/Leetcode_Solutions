class Solution {
public:
    
    bool valid(int i,int j,int n,int m){
        
        if(i<0||j<0||i>=n||j>=m) return false;
        return true;
    }
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
       set<pair<int, pair<int,int>>>st;
        st.insert({0,{0,0}});
        
        vector<int> dir[]={{0,1},{0,-1},{1,0},{-1,0}};
        
        vector<vector<int>>dp(n,vector<int>(m,m*n+1));
        
        while(st.size()){
            
            int costtillhere = st.begin()->first;
            
            int x = st.begin()->second.first;
            
            int y = st.begin()->second.second;
            
            st.erase(st.begin());
            
            for(int k=0;k<4;k++){
                
                int i = x+dir[k][0];
                int j = y+dir[k][1];
                
               
                
                if(valid(i,j,n,m)){
                     int costfromparent = grid[i][j];
                    
                    if(dp[i][j]>costtillhere+costfromparent){
                        
                        dp[i][j]=costtillhere+costfromparent;
                        st.insert({dp[i][j],{i,j}});
                    }
                }
            }
        }
        
        return dp[n-1][m-1];
        
    }
};