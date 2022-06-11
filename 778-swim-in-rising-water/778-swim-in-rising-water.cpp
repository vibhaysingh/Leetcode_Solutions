int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

class Solution {
public:
    
    
    
    
    bool correct(int x,int y,int n,int m){
        
        if(x<0||y<0||x>=n||y>=m) return false;
        return true;
    }
    
    
    bool valid(int mid,vector<vector<int>>& grid){
        
         int n = grid.size();
        int m = grid[0].size();
        
        set<pair<int,int>>st;
        
        queue<pair<int,int>>q;
        
        if(grid[0][0]>mid) return false;
        
        st.insert({0,0});
        q.push({0,0});
        while(!q.empty()){
            
            auto z = q.front();
              q.pop();
            
            if(z.first==n-1 && z.second==m-1) return true;
            
            for(int j=0;j<4;j++){
                
                int x = dx[j]+z.first;
                int y = dy[j]+z.second;
                
                if(correct(x,y,n,m)&&grid[x][y]<=mid&&st.count({x,y})==0){
                    q.push({x,y});
                    st.insert({x,y});
                }
            }
            
        }
        return false;
        
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        
        
        int mx = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                mx = max(mx,grid[i][j]);
            }
        }
        
        int low=0,high=mx,ans;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            if(valid(mid,grid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
        
        
    }
};