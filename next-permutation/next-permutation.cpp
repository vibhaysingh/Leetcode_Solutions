class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int j=n-2;
        while(j>-1 && nums[j]>=nums[j+1]){
            j--;
        }
        
        if(j==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int i;
        
        for( i=n-1;i>=0;i--){
            
            if(nums[i]>nums[j]){
                swap(nums[i],nums[j]);
                break;
            }
            
        }
        
        // cout<<i<<j<<endl;
        
        reverse(nums.begin()+j+1,nums.end());
        
        
        
        
        
        
        
    }
};