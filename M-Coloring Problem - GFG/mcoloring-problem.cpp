// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool valid(int clr,int node,bool graph[101][101],int color[],int V){
    
    
    for(int i=0;i<V;i++){
        
        if(i==node) continue;
        
        if(graph[node][i]==1 && color[i]==clr) return false;
    }
    
    return true;
}

bool dfs(int node, bool graph[101][101],int m,int V,int color[]){


  if(node==V) return true; // all nodes are coloured return true
  
  
  /// assign the colors to every node
  
  for(int clr= 1;clr<=m; clr++){
      
      if(valid(clr,node,graph,color,V)){
          
          color[node]=clr;
      
          if(dfs(node+1,graph,m,V,color)) return true;
          
          color[node]=-1;
        }
    }
  
  return false;
    
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    
   int color[V];
   
   memset(color,-1,sizeof color);
   
   return dfs(0,graph,m,V,color);
   
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends