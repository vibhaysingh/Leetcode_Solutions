int dp[100005][2][3];


class Solution {
public:
    
    
    int solver(int idx,int k,int own,vector<int>&prices){
        
        int n = prices.size();
        if(idx==n||k==0) return 0;
        
        
        if(dp[idx][own][k]!=-1) return dp[idx][own][k];
        
        // if i have stock
        
        
        
        if(own){
            
            // sell and not sell
            
            int op1 = prices[idx] + solver(idx+1,k-1,0,prices);
            int op2 = 0+ solver(idx+1,k,1,prices);
            
            return dp[idx][own][k]=max(op1,op2);
        }
        else{
            
            // buy & not buy
            
              int op1 = -prices[idx] + solver(idx+1,k,1,prices);
              int op2 = 0 + solver(idx+1,k,0,prices);
            return dp[idx][own][k]=max(op1,op2);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,2,0,prices);
    }
};