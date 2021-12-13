int dp[5005];
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        
        int n = env.size();
        fill(dp,dp+5005,1);
        
        vector<pair<int,int>>vp;
        
        for(int i=0;i<n;i++)
        {
            vp.push_back({env[i][0],env[i][1]});
        }
        
        sort(vp.begin(),vp.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(vp[j].first<vp[i].first&&vp[j].second<vp[i].second&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        
        return *max_element(dp,dp+5005);
    }
};