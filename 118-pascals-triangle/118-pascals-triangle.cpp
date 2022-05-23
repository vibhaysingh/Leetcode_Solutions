class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>v(n,vector<int>());
        
        v[0].push_back(1);
        
        if(n==1) return v;
        
        v[1].push_back(1);
        v[1].push_back(1);
        
        for(int i=2;i<n;i++){
            
            v[i].push_back(1);
            
            for(int j=0 ;j<v[i-1].size()-1;j++){
                
                v[i].push_back(v[i-1][j]+v[i-1][j+1]);
            }
            
             v[i].push_back(1);
        }
        
        return v;
        
    }
};