// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > q;
        
        vector<int>d(V,1e9),vis(V,0);
        
        d[0]=0;
        
        q.push({0,0});
        int ans=0;
        while(!q.empty()){
            
            int u = q.top().second;
            int wt = q.top().first;
            q.pop();
            
            if(vis[u])continue;
            vis[u]=1;
            ans+=wt;
            
            for(auto k:adj[u]){
                
                int v = k[0];
                int w = k[1];
                
                if(!vis[v] && d[v]>w){
                    d[v]=w;
                    q.push({w,v});
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends