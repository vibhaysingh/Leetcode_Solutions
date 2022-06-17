
int dp[10005];

class Solution {
public:
    
//     bool solver(int idx, vector<int>&nums)
//     {
//         if(idx>=nums.size())
//             return false;
//         if(idx==nums.size()-1)
//         {
//             return true;
//         }
        
//         if(dp[idx]!=-1)
//         {
//             return dp[idx];
//         }
    
        
        // for(int i=1;i<=nums[idx];i++)
        // {
        //     if(solver(idx+i,nums))
        //     {
        //         return dp[idx+i]=true;
        //     }
        // }
        // return dp[idx]=false;
//     }
    
    bool canJump(vector<int>& nums) {
        
        // memset(dp,-1,sizeof dp);        
        // return solver(0,nums);
        
        // memset(dp,0,sizeof dp);  
        
        int m =nums[0];
        int n = nums.size();
        
        vector<int>dp(n,0);
        
         dp[0]=1;
        int mx=0;
        
        for(int i=0;i<n;i++){
            
            
            if(mx<i) return false;
            
            if(i+nums[i]<mx)continue;
          
            mx=max(mx,i+nums[i]);
            
            
        }
        
        return mx>=n-1;
        
        
        
        
        
        if(n==1)return true;
        
        for(int i=1;i<n;i++)
        {
            if(m<i)
                return false;
            m= max(m,i+nums[i]);
            
            if(m>=n-1)
                return true;
        }
        
        return false;
        
        
    }
};