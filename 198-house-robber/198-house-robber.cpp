class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,0);
        
        dp[0]=0;
        
        for(int i=0;i<n;i++){
            
           if(i>1){
               
               dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
           }
            else{
                
                if(i==0){
                    dp[i]=nums[i];
                    
                }
                else if(i==1){
                   
                    dp[i]=max(nums[0],nums[1]);
                }
            }
        }
        
       return dp[n-1]; 
    }
};