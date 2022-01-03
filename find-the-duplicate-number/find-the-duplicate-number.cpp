class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        // M-1 Sorting
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;i++){
            
            if(nums[i-1]==nums[i])
                return nums[i];
        }
        return -1;
        
        
        
        
        
    }
};