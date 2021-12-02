class Solution {
public:
    
    vector<vector<int>>ans;
    void dfs(int s,vector<vector<int>>& graph, vector<int>&temp,int target)
    {
        
        temp.push_back(s);
        if(s==target)
        {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        for(auto k:graph[s])
        {
            dfs(k,graph,temp,target); 
        }
        temp.pop_back();
        return;
            
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();        
        vector<int>vis(n,false);
        vector<int>temp;        
        dfs(0,graph,temp,n-1);        
        return ans;
        
    }
};