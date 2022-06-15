class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        
        int cnt=0;
        
        for(auto k:nums){
            sum+=k;
            if(k==0)cnt++;
        }
        
        
        int val = sum+target;
        
        if(val%2==1||val<0) return 0;
        
        val/=2;
        
        cout<<val<<endl;
        
        // if(sum-target==0) return (1<<cnt);
        int n = nums.size();
        
       vector< vector<int>>dp(n+1,vector<int>(val+1,0));
        
        for(int i=0;i<=val;i++){
            
            dp[0][i] = 0;
        }
        
        for(int i=0;i<=n;i++){
            
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            
            for(int j=0;j<=val;j++){
                
                
                if(nums[i-1]>j){
                    
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    
                    dp[i][j] = (dp[i-1][j]+ dp[i-1][j-nums[i-1]]);
                }
            }
        }
        
        return dp[n][val];
        
    }
};