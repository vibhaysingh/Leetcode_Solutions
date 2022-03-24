class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        
        int n = graph.size();
        vector<vector<int>>adj(n);
        
        for(int i=0;i<n;i++){
            
            for(auto k:graph[i]){
                
                adj[k].push_back(i);
            }
        }
        
        queue<int>q;
        vector<int>ind(n,0);
        
        for(int i=0;i<n;i++){
            
            for(auto k:adj[i]){
                
                ind[k]++;
                
            }
           
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            
            if(ind[i]==0){
                q.push(i);
                ans.push_back(i);
                // cout<<i<<endl;
            }
        }
        
        while(!q.empty()){
            
            int l = q.size();
            
            while(l--){
                
                auto x = q.front();
                q.pop();
                
                for(auto k:adj[x]){
                    
                    ind[k]--;
                    
                    if(ind[k]==0) {
                        ans.push_back(k);
                        q.push(k);
                    }
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
        
        
        
        
    }
};