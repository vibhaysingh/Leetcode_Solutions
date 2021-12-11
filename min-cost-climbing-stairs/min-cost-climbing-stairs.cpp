
int dp[1005];
class Solution {
public:
    
    int solver(int idx,vector<int>&cost)
    {
        if(idx>cost.size())
           return INT_MAX;   
        if(idx==cost.size())
            return 0;
        
        // base case if one stair only
        if(idx==cost.size()-1)
        {
            return cost[idx];
        }
        
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        
        int temp = cost[idx]+ min(solver(idx+1,cost),solver(idx+2,cost));
        
        return dp[idx] = temp;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        memset(dp,-1,sizeof dp);
        
        return min(solver(0,cost),solver(1,cost));
    }
};