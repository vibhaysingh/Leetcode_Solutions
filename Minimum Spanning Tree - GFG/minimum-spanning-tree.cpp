// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	
	int par[1001],sz[1001];
	
	Solution(){
	  	for(int i=0;i<1001;i++){
	    par[i]=i;
	    sz[i]=1;
	}  
	}
	

	
	int findPar(int node){
	    
	    if(par[node]==node)return node;
	    
	    return par[node]=findPar(par[node]);
	}
	
	void Union(int a,int b){
	    
	    a = findPar(a);
	    b = findPar(b);
	    
	    if(a!=b){
	        
	        if(sz[a]<sz[b]){
	            swap(a,b);
	        }
	        
	        par[b] = a;
	        
	        sz[a]+=sz[b];
	    }
	    
	    
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<vector<int>>v;
        
        for(int i=0;i<V;i++){
            
            for(auto k:adj[i]){
                
                v.push_back({k[1],i,k[0]});
            }
        }
        
        sort(v.begin(),v.end());
        int ans=0;
        
        for(auto k:v){
            
            if(findPar(k[1])!=findPar(k[2])){
                
                Union(k[1],k[2]);
                ans+=k[0];
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