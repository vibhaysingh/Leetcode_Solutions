
class TreeAncestor {
    int dp[21][50005];
public:
  
    int sz;
    
    TreeAncestor(int n, vector<int>& parent) {
        
        memset(dp,-1,sizeof dp);
        
        sz=n;
        
        for(int i=0;i<n;i++){
            
            dp[0][i]=parent[i];
        }
        
        for(int i=1;i<21;i++){
            
            for(int j=0;j<n;j++){
                if(dp[i-1][j]>=0)
                dp[i][j]=dp[i-1][dp[i-1][j]];
                // cout << dp[i][j] << ' ';
            }
            // cout << '\n';
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        // if(k>ceil(log2(sz))) return -1;
        
        for(int i=0;i<21;i++){
            
            int mask=(1<<i);
            
            
          
            
            if((mask&k)>0){
                
                node = dp[i][node];
                
                if(node==-1) return -1;
            }
            
        }
        
        return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */