// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>adj){
	    
	    
	    
	    // Code here
	    
	    vector<int>dis(n,1e9);
	    
	    dis[0]=0;
	    
	    bool f = false;
	    
	    for(int i=0;i<n;i++){
	        
	        for(auto k:adj){
	            
	            int u = k[0];
	            int v = k[1];
	            int w = k[2];
	            
	            if(dis[v]>dis[u]+w){
	                dis[v]=dis[u]+w;
	                
	                if(i==n-1)f=true;
	            }
	        }
	    }
	    
	    
	    return f;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends