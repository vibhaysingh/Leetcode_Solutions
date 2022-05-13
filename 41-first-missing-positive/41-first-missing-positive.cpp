class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        
        map<int,int>mp;
        
        for(auto k:nums)mp[k]++;
        
        int ans=1;
        
        for(auto k:mp){
            
            if(k.first>0 && k.first!=ans){
                
                break;
            }
            else if(k.first>0){
                ans=k.first+1;
            }
    }
    return ans;
                    }
};