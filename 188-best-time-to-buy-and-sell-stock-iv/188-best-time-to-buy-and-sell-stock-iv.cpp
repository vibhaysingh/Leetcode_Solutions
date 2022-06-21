int dp[1005][205];
class Solution {
public:
    
    int solver(int idx,int tno,int k,vector<int>& prices){
        
        int n = prices.size();
        if(tno==k||idx==n ) return 0;
        
        
        if(dp[idx][tno]!=-1) return dp[idx][tno];
        
        
        if((tno%2)==0){ // buy
            
            
            int op1  = -prices[idx] + solver(idx+1,tno+1,k,prices);
            int op2  = 0 + solver(idx+1,tno,k,prices);
            
            return  dp[idx][tno]= max(op1,op2);
        }
        else{
            
            int op1  = prices[idx] + solver(idx+1,tno+1,k,prices);
            int op2  = 0 + solver(idx+1,tno,k,prices);
            
            return  dp[idx][tno]=max(op1,op2);
            
        }
        
        
    }
    
    
    
    
    
    int maxProfit(int ttl, vector<int>& prices) {
        
        memset(dp,-1,sizeof dp);
        
        int n = prices.size();
        
        ttl*=2;
        
        return solver(0,0,ttl,prices);
    }
};