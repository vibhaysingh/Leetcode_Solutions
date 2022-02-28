
int dp[205][205];

class Solution {
public:
    
    int solver(int idx,vector<int>& nums, int k){
        
        int n = nums.size();
        
        if(idx==n) return 0;
        
        if(k==0){
            
            return INT_MAX;
        }
        
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        
        
        long long sum = 0;
        long long mx =0;
        long long temp = INT_MAX;
        
        for(int i=idx;i<n;i++){
            
            mx = max((long long)nums[i],mx);
            sum+=nums[i];
            
            temp = min (temp , mx*(i-idx+1)-sum + solver(i+1,nums,k-1));
        }
        
        return dp[idx][k] = temp;
    }
    
    
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,nums,k+1);
        
    }
};