class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            
            if(ans.back()>=nums[i]){
                
                auto k = lower_bound(ans.begin(),ans.end(),nums[i]);
                *k=nums[i];
                
            }else{
                ans.push_back(nums[i]);
            }
        }
        
        return ans.size()>=3;
        
        
    }
};

/// 1 2 8 4