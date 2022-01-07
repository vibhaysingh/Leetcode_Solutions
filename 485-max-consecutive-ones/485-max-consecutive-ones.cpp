class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i=0;
        int j =0;
        int n = nums.size();
        int ans =0;
        
        while(j<n){
            
            if(nums[j]==0){
                i=j+1;
                
            }else{
                
                ans = max(ans,j-i+1);
            }
            
            j++;
            
        }
        // cout<<i<<j<<endl;
        
       // ans =max(ans,j-i);
        
        return ans;
        
    }
};