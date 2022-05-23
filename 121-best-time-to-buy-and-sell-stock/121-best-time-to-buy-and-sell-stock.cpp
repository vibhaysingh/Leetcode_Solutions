class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans=0;
        
        int prevmin=prices[0];
        
        for(int i=0;i<prices.size();i++){
            
            ans=max(ans,prices[i]-prevmin);
            
            prevmin = min(prevmin,prices[i]);
        }
        
        return ans;
        
    }
};