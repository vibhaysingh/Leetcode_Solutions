class Solution {
public:
    vector<int> getRow(int r) {
        
        vector<int>v(r+1,0);
        
        v[0]=1;
        
        for(int i=1;i<r+1;i++){
            
            v[i]=1;
            
            for(int j=i-1;j>=1;j--){
                
                v[j] = v[j-1]+v[j];
            }
            
            // for(auto k:v)cout<<k<<" ";cout<<endl;
        }
        
        return v;
        
    }
};