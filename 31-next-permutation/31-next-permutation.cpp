class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        int n = nums.size();
        
        int dip=-1;
        
        for(int i=n-2;i>=0;i--){
            
            if(nums[i]<nums[i+1]){
                dip=i;
                break;
            }
        }
        
        if(dip==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int diff = abs(nums[dip+1]-nums[dip]);
        
        int it = dip+1;
        
        for(int i=dip+2;i<n;i++){
            
            if(abs(nums[i]-nums[dip])<=diff && nums[i]>nums[dip])
            {
                diff=abs(nums[i]-nums[dip]);
                it=i;
            }
        }
        
        // cout<<dip<<" "<<it<<endl;
        
        swap(nums[dip],nums[it]);
        
        reverse(nums.begin()+dip+1,nums.end());
        
        return;
        
    }
};