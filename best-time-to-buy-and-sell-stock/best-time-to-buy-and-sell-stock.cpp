class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int prevMin=prices[0];
        int ans=0;
        
        for(int i=1;i<n;i++){
            
            ans = max(ans,prices[i]-prevMin);
            prevMin=min(prevMin,prices[i]);
        }
        return ans;
    }
};