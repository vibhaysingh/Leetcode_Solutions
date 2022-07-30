class Solution {
public:
    int maxSubArray(vector<int>& nums) {        
       int n = nums.size();        
       int curr=nums[0];
        int ans=nums[0];        
        for(int i=1;i<n;i++){            
            if(curr>0){                
                curr+=nums[i];                
                ans=max(ans,curr);
            }
            else{
                
                 ans=max(ans,curr);
                 curr=nums[i];
                 ans=max(ans,curr);
            }
        }        
        return ans;        
    }
};