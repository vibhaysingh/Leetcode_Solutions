/*

undirected graph

An undirected graph has an Eulerian cycle if and only if every vertex has even degree, and all of its vertices with nonzero degree belong to a single connected component.
An undirected graph has an Eulerian trail/path if and only if exactly zero or two vertices have odd degree, and all of its vertices with nonzero degree belong to a single connected component

directed graph

A directed graph has an Eulerian cycle if and only if every vertex has equal in degree and out degree, and all of its vertices with nonzero degree belong to a single strongly connected component.

A directed graph has an Eulerian trail if and only if at most one vertex has (out-degree) − (in-degree) = 1, at most one vertex has (in-degree) − (out-degree) = 1, every other vertex has equal in-degree and out-degree, and all of its vertices with nonzero degree belong to a single connected component of the underlying undirected graph


*/

// apply hierhlozer algorithm
// feury algo also works(but don't have knowlwdge od it)

class Solution {
public:
    
    void dfs(string node,vector<string>&path,map<string , priority_queue< string , vector<string> , greater<string> > > &mp){

    while(!mp[node].empty())
    {
        string next=mp[node].top();
        mp[node].pop();
        dfs(next,path,mp);
    }
    path.push_back(node);
}

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        
        vector<string>path;
map<string , priority_queue< string , vector<string> , greater<string> > > mp;

    unordered_map<string,int>indegree; 
    unordered_map<string,int>outdegree; 
    for(auto k: tickets)
    {
        mp[k[0]].push(k[1]);

        outdegree[k[0]]++;
        indegree[k[1]]++;
    }
        
        string start;
    
 // this is used to find start point but we are forced to do from "JFK";
    // for(auto k: outdegree)
    // {
    //     if(k.second - indegree[k.first]==1)
    //     {
    //         start= k.first;
    //     }
    // }
    // if(start.empty()) start= mp.begin()->first;
        
        start="JFK";
    dfs(start,path,mp);

    reverse(path.begin(),path.end());
    return path;

        
    }
};