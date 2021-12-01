class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        
        vector<pair<int,int>>adj[n+1];
        
        for(auto k:times){
            
            adj[k[0]].push_back({k[1],k[2]});
        }
        
        int source = k;
        // min-heap ; In pair => (dist,from)
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
// 1-indexed array for calculating shortest paths to ith node from given source node;
	vector<int> distTo(n+1,INT_MAX); 	
        
        distTo[source]=0;
        pq.push({0,source});	// (dist,from)
        
        while(!pq.empty())
        {
            
            int dist = pq.top().first;
		    int prev = pq.top().second;
		    pq.pop();
            
            for(auto k:adj[prev])
            {
                int next = k.first;
			    int nextDist = k.second;
                
                if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push({distTo[next], next});
			}
            }
        }
        
        int ans =0;
    
        for(int i=1;i<n+1;i++)
        {
            if(distTo[i]==INT_MAX)
                return -1;
            else
            {
                ans = max(ans,distTo[i]);
            }
        }
        
        return ans;
        
    }
};