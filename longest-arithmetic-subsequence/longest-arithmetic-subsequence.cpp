class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_map<int,int>mp[n];
        
        int ans=1;
       
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int cd = nums[i]-nums[j];
                
                mp[i][cd]=2;
                ans = max(ans,mp[i][cd]);
                if(mp[j].find(cd)!=mp[j].end())
                {
                    mp[i][cd]=mp[j][cd]+1;
                    ans = max(ans,mp[i][cd]);
                }
            }
        }
        
        return ans;
    }
};