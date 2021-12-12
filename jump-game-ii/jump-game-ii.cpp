unsigned int dp[10005];

class Solution {
public:
    
//     int solver(int idx, vector<int>&nums)
//     {
//         if(idx>=nums.size())
//             return 10005;
//         if(idx==nums.size()-1)
//         {
//             return 0;
//         }
        
//         if(dp[idx]!=-1)
//         {
//             return dp[idx];
//         }
        
//         int f=10005;
        
//         for(int i=1;i<=nums[idx];i++)
//         {
//             f= min(f,1+solver(idx+i,nums));
//         }
//         return dp[idx]=f;
//     }
    
    int jump(vector<int>& nums) {
        
//         memset(dp,-1,sizeof dp);
        
//         return solver(0,nums);
        
        int n = nums.size();
        
        for(int i=0;i<n+1;i++)
        {
            dp[i] = 10005;
        }
        
        dp[n-1]=0;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=1;j<=nums[i];j++)
            {
                if(i+j<n)
                {
                    dp[i]= min(dp[i],1+dp[i+j]);
                }
            }
        }
        
        return dp[0];
    }
};