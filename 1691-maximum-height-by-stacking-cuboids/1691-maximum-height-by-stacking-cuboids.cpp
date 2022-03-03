class Solution {
public:
    int maxHeight(vector<vector<int>>& cub) {
        
        int n = cub.size();
        
        for(auto &c:cub){
            sort(c.begin(),c.end());
        }
        
        
        sort(cub.begin(),cub.end());
        
        vector<int>dp(n+1,0);
        
        for(int i=0;i<n;i++){
            
           dp[i] = cub[i][2];
            
            for(int j=0;j<i;j++){
                
                if ((cub[i][0] >= cub[j][0]) && (cub[i][1] >= cub[j][1]) && (cub[i][2] >= cub[j][2]))
                {
                    dp[i] = max(dp[i], dp[j] + cub[i][2]);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
        
        
        
    }
};