class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
       
        
      int n = nums.size();  
      unordered_map<int,int>mp;
        
        for(auto x:nums) mp[x]++;
        
        vector<vector<int>>v(n+1);
        
        for(auto x:mp){
            
            v[x.second].push_back(x.first);
        }
        
        vector<int>ans;
        
        for(int i=n;i>=0;i--){
            for(auto j:v[i]){
                ans.push_back(j);
                
                if(ans.size()==k) return ans;
            }
        }
        
        return {};
        
    }
};