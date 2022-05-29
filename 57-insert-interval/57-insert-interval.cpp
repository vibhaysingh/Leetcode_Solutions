class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& nwi) {
        
        
        
        int n = in.size();
        
        if(n==0) return {{nwi[0],nwi[1]}};
        
        vector<vector<int>>ans;
        
        bool f= true;
        int i=0;
        for( i=0;i<n;i++){
            
            // if(completey outside)
            
            if(in[i][1]<nwi[0]){
                ans.push_back(in[i]);
               
            }
            else{
                break;
            }
            
        }
        
        // cout<<i<<endl;
        
        if(i==n){
             ans.push_back(nwi);
            return ans;
        }
        
        
       
        if(in[i][0]>nwi[1])
        ans.push_back(nwi);
        else{
             // cout<<ans.size()<<endl;
            vector<int>x;
            x.push_back(min(nwi[0],in[i][0]));
            x.push_back(max(nwi[1],in[i][1]));
            ans.push_back(x);
        }
        
        // cout<<ans.size()<<endl;
        
        while(i<n){
            
            vector<int>z = ans.back();
            
            // if(z==in[i]) continue;
            
            if(z[1]<in[i][0]){
                ans.push_back(in[i]);
            }
            else{
              vector<int>x;
                x.push_back(z[0]);
                x.push_back(max(z[1],in[i][1]));
                
                // ans.push_back(x);
                ans.back()=x;
                
            }
            i++;
        }
        return ans;
        
    }
};