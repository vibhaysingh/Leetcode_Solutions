
int dp[1005];
class Solution {
public:
    
//     int solver(int idx,vector<int>&cost)
//     {
//         if(idx>cost.size())
//            return INT_MAX;   
//         if(idx==cost.size())
//             return 0;
        
//         // base case if one stair only
//         if(idx==cost.size()-1)
//         {
//             return cost[idx];
//         }
        
//         if(dp[idx]!=-1)
//         {
//             return dp[idx];
//         }
        
//         int temp = cost[idx]+ min(solver(idx+1,cost),solver(idx+2,cost));
        
//         return dp[idx] = temp;
//     }
    int minCostClimbingStairs(vector<int>& cost) {
        
//         memset(dp,-1,sizeof dp);
        
//         return min(solver(0,cost),solver(1,cost));
        
        memset(dp,0,sizeof dp);
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        cost.push_back(0);
        int n = cost.size()-1;
        for(int i=2;i<=n;i++)
        {
            dp[i]= cost[i]+min(dp[i-1],dp[i-2]);
        }
        
        return dp[n];
    }
};