class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        
        vector<vector<int>>adj(n);
        
        for(auto k:pre)
        {
            adj[k[1]].push_back(k[0]);
        }
        
        vector<int>indegree(n,0);
        
        
        for(int i=0;i<n;i++)
        {
            for(auto k:adj[i])
            {
                indegree[k]++; // calculating indegree of all nodes
            }
        }
        
        queue<int>q;
        
        // push all nodes with zero indegree into queue
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int>ans;
        
        int cnt=0;
        
        // cout<<q.size()<<" "<<q.front()<<endl;
        
        while(!q.empty())
        {
            
           int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for(auto v : adj[u])
            {
                
                if(--indegree[v]==0){ // if indegree becomes 0 push into queue
                    q.push(v);
                }
            }
            
            cnt++;
            
          
            
            
        }
        
        // if cnt not equal to no of nodes then toposort not possible
        
        if(cnt!=n) return {};
        return ans;
    }
};