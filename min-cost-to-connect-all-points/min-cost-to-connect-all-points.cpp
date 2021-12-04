
struct node{
    
    pair<int,int>a,b;
    int cost;
    node(pair<int,int>a,pair<int,int>b,int cost)
    {
        this->a = a;
        this->b = b;
        this->cost = cost;
    }
    
};
  bool comp(node a, node b)
    {
        return a.cost < b.cost;
    }

class Solution {
public:
    
    
  
    
    int findParent(int u, vector<int>&parent)
    {
        if(u==parent[u]) return u;        
        return parent[u]= findParent(parent[u],parent);
    }
    
    void unionn(int a, int b,vector<int>&parent,vector<int>&rank)
    {
        a= findParent(a,parent);
        b= findParent(b,parent);
        
        // parent ka rank jyada hota hai hmesha
        
        if(rank[a]<rank[b])
        {
            parent[a]=b;
        }
        else if(rank[b]<rank[a])
        {
            parent[b]=a;
        }
        else // equal rank
        {
            parent[b]=a; // b ka parent a ban gya hai to a ka rank increase kr do
            rank[a]++;
        }
    }    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<node>edges;
        
        int n = points.size();
        
        map<pair<int,int>,int>mp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int cost = abs(x1-x2)+abs(y1-y2);
                
                  pair<int,int>a= make_pair(x1,y1);
                  pair<int,int>b= make_pair(x2,y2);
                
                edges.push_back(node(a,b,cost));
            }
        }
        
        sort(edges.begin(),edges.end(),comp);
        
        vector<int>parent(n);
        vector<int>rank(n,0);
        
        for(int i=0;i<n;i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            parent[i]=i;
            mp[{x1,y1}]=i;
        }
        
        int cost = 0;
        
        for(auto k: edges)
        {
            if(findParent(mp[k.a],parent)!=findParent(mp[k.b],parent))
            {
                cost+=k.cost;
                unionn(mp[k.a],mp[k.b],parent,rank);
            }
        }
        
        return cost;
        
    }
};