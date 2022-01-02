class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        
        int n = intv.size();
        
        sort(intv.begin(),intv.end());
        
        vector<vector<int>>ans;
        
        ans.push_back(intv[0]);
        
        for(int i=1;i<n;i++){
            
            auto v = ans.back();
            
            int a = v[0];
            int b = v[1];
            int c = intv[i][0];
            int d = intv[i][1];
            
            if(c<=b){
                
                v[1]= max(b,d);
                ans.back()=v;
                
                
            }else
            {
                ans.push_back(intv[i]);
            }
            
            
            
            
        }
        
        return ans;       
        
        
    }
};