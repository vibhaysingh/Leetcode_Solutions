
int dp[10005];

class Solution {
public:
    
    bool solver(int idx, vector<int>&nums)
    {
        if(idx>=nums.size())
            return false;
        if(idx==nums.size()-1)
        {
            return true;
        }
        
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
    
        
        for(int i=1;i<=nums[idx];i++)
        {
            if(solver(idx+i,nums))
            {
                return dp[idx+i]=true;
            }
        }
        return dp[idx]=false;
    }
    
    bool canJump(vector<int>& nums) {
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,nums);
    }
};