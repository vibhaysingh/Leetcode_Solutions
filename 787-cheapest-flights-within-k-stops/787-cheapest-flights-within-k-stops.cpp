class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        vector<int>dis(n,INT_MAX);
        
        dis[src]=0;
        
        for(int i=0;i<=k;i++){
            
            vector<int>temp = dis;
            
            for(auto f:flights){
                
                int u = f[0];
                int v = f[1];
                int wt = f[2];
                
                if(dis[u]!=INT_MAX && temp[v]>dis[u]+wt){
                    temp[v]=dis[u]+wt;
                }
            }
            
         dis = temp;
        }
        
      
        
        if(dis[dst]==INT_MAX) return -1;
        
        return dis[dst];
    }
};