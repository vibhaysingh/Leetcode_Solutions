class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        int ans = *max_element(nums.begin(),nums.end());
        
        int currmin=1;
        int currmax=1;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==0){
                currmin=1;
                currmax=1;
                continue;
            }
            else{
                int t = currmax;
                currmax = max({currmax*nums[i],currmin*nums[i],nums[i]});
                currmin = min({t*nums[i],currmin*nums[i],nums[i]});
            }
            
            ans=max({ans,currmax});
        }
        
        return ans;
        
    }
};