int dp[2505][2505];

class Solution {
public:
    
    int solver(int prev,int curr,vector<int>&nums)
    {
        
       if(curr>=nums.size())
           return 0;
            
     
        
        if(prev!=-1&&dp[prev][curr]!=-1)
            return dp[prev][curr];
        
        int op1=0,op2=0;
        if(prev==-1||nums[prev]<nums[curr])
        {
            op1 = 1+solver(curr,curr+1,nums);
        }
        
            op2= solver(prev,curr+1,nums);
        
        
        if(prev!=-1)
        return dp[prev][curr]=max(op1,op2);
        else
            return max(op1,op2);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        return solver(-1,0,nums);
        
    }
};