int dp[100005][2][3];


class Solution {
public:
    
    
//     int solver(int idx,int k,int own,vector<int>&prices){
        
//         int n = prices.size();
//         if(idx==n||k==0) return 0;
        
        
//         if(dp[idx][own][k]!=-1) return dp[idx][own][k];
        
//         // if i have stock
        
        
        
//         if(own){
            
//             // sell and not sell
            
//             int op1 = prices[idx] + solver(idx+1,k-1,0,prices);
//             int op2 = 0+ solver(idx+1,k,1,prices);
            
//             return dp[idx][own][k]=max(op1,op2);
//         }
//         else{
            
//             // buy & not buy
            
//               int op1 = -prices[idx] + solver(idx+1,k,1,prices);
//               int op2 = 0 + solver(idx+1,k,0,prices);
//             return dp[idx][own][k]=max(op1,op2);
//         }
//     }
    
    int maxProfit(vector<int>& prices) {
        
        memset(dp,0,sizeof dp);
        
        int n = prices.size();
        
        vector<vector<int>>ahead(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        
        for(int idx=n-1;idx>=0;idx--){
            
            for(int k=1;k<=2;k++)
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
        
        
        return curr[0][2];
    }
};