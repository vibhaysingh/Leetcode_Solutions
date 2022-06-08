class Solution {
public:
    
    void dfs( int node,vector<int> adj[],vector<int>&vis){
        vis[node]=1;
        for(auto k:adj[node]){
            if(!vis[k])dfs(k,adj,vis);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int cnt=0;
        vector<int>vis(n,0);
        vector<int>adj[n];
        
        if(connections.size()<n-1) return -1;
        
        for(auto k:connections){
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        
        return cnt-1;
        
    }
};