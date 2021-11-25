class Solution {
public:
    
   bool hasCycle(int src, vector<int>&vis,vector<int>&dfsvis,vector<vector<int>>&adj){
       
       vis[src]=1;
       dfsvis[src]=1;
       
       for(auto k:adj[src]){
           
           if(!vis[k])
           {
               if(hasCycle(k,vis,dfsvis,adj))
                   return true;
           }
           else if(dfsvis[k])
               return true;
       }
       
       dfsvis[src] = false;
       
       return false;
       
   } 
    
  void topoSort(int src, vector<int>&vis,stack<int>&st,vector<vector<int>>&adj)
  {
      vis[src]=1;
      
      for(auto k : adj[src])
      {
          if(!vis[k]){
              topoSort(k,vis,st,adj);
          }
      }
      
      st.push(src);
  }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>>adj(n);
        
        for(auto k:pre){
            
            adj[k[1]].push_back(k[0]);
            
        }
        
        vector<int>ans;
        vector<int>vis(n,false);
        vector<int>dfsvis(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(hasCycle(i,vis,dfsvis,adj))
                    return ans;
            }
        }
        
        stack<int>st;
        vis.assign(n,false);
        
           for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                topoSort(i,vis,st,adj);
            }
               
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
        
        
        
        
    }
};