class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0;
        int j = 1;
        int n = nums.size();
        int k=1;
        if(n==0) return 0;
        
        while(j<n){
            
            if(nums[i]==nums[j]){
                j++;
            }else{
                
                i++;
                k++;
                nums[i]=nums[j];
            }
        }
        
        return k;
        
        
    }
};