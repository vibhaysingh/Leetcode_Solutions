class Solution {
public:
    vector<int>vis;
    vector<int>tin,low;
    int timer;
    vector<vector<int>>ans;
    
    void dfs(int s,vector<int>adj[],int p)
    {
        vis[s]=1;
        tin[s]=low[s]=timer++;
        // cout<<s<<endl;
        
        for(auto k:adj[s])
        {
            
            if(k==p) // if parent then continue
                continue;
            if(vis[k]) // if already visited
            {
                low[s] = min(low[s], tin[k]);
            }
            else
            {
               dfs(k, adj,s);
               low[s] = min(low[s], low[k]);
               if (low[k] > tin[s])
                ans.push_back({s,k});
            }
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vis.assign(n,0);
        tin.assign(n,-1); // discovery time
        low.assign(n,-1); // lowest node connected by the childrens
        timer=0; // keep track of timer
        vector<int>adj[n]; // array of vectors where array indices are nodes and 
        // vector associated with that index stores its neighbours
        
        for(auto k:connections) // make adjacency list
        {
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) // perform dfs for every node to make dfs tree
            {
                dfs(i,adj,-1); // arguments (node , adj list , parent)
            }
        }
        return ans;
    }
};