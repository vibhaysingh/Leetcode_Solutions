class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        
        
        sort(in.begin(),in.end());
         vector<vector<int>>ans;
        
         ans.push_back(in[0]);
        int n = in.size();
        
        for(int i=1;i<n;i++){
            
            auto prev = ans.back();
            auto curr = in[i];
            
             vector<int>temp;
            
             if(curr[0]<=prev[1]){
                 
                 temp.push_back(prev[0]);
                 temp.push_back(max(curr[1],prev[1]));
                 
                 ans.back()=temp;
                 
             }
            else{
                ans.push_back(curr);
            }
        }
        
        return ans;
        
        
    }
};