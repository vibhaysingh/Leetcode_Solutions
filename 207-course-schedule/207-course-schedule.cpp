class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        
        vector<int>adj[n];
         vector<int>ind(n,0);
        for(auto k:pre){
            
            adj[k[1]].push_back(k[0]);
            
            ind[k[0]]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            
            if(ind[i]==0)q.push(i);
        }
        
        int cnt=0;
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            
            for(auto k:adj[u]){
                
                ind[k]--;
                
                if(ind[k]==0){
                    q.push(k);
                }
            }
            cnt++;
        }
        
        return cnt==n;
       
    }
};