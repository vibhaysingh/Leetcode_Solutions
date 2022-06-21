int dp[1005][2][105];
class Solution {
public:
    int maxProfit(int ttl, vector<int>& prices) {
        
        memset(dp,0,sizeof dp);
        
        int n = prices.size();
        
        vector<vector<int>>ahead(2,vector<int>(ttl+1,0));
        vector<vector<int>>curr(2,vector<int>(ttl+1,0));
        
        for(int idx=n-1;idx>=0;idx--){
            
            for(int k=1;k<=ttl;k++)
            {
                for(int own = 0;own<=1;own++){
                    
                      
        if(own){
            
            // sell and not sell
            
            int op1 = prices[idx] +  ahead[0][k-1];
            int op2 = 0+ ahead[1][k];
            
             curr[own][k]=max(op1,op2);
        }
        else{
            
            // buy & not buy
            
              int op1 = -prices[idx] + ahead[1][k];
              int op2 = 0 + ahead[0][k];
             curr[own][k]=max(op1,op2);
        }
                }
            }
            
            ahead=curr;
        }
        
        
        return curr[0][ttl];
    }
};