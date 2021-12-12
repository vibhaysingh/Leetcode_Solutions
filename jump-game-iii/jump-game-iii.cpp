int dp[100005];

class Solution {
public:
    
    bool solver(int idx,vector<int>&arr,vector<int>&vis)
    {
        
        int n = arr.size();
        
        if(idx<0||idx>=n||vis[idx])
            return false;
        // cout<<idx<<endl;
        if(arr[idx]==0)
        {
            return true;
        }
        
        if(dp[idx]!=-1)
            return dp[idx];
        
         vis[idx]=1;
        
        if(solver(idx+arr[idx],arr,vis)||solver(idx-arr[idx],arr,vis))
        {
            return dp[idx]=true;
        }
        
        return dp[idx]=false;
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        
        memset(dp,-1,sizeof dp);
        vector<int>vis(arr.size(),0);
        
        return solver(start,arr,vis);
    }
};