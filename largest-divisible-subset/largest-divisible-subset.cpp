class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        
        int dp[n];
        int idx[n];
        // memset(dp,0,sizeof dp);
        memset(idx,-1,sizeof idx);
        fill(dp,dp+n,1);
        
        
        dp[0]=1;
        idx[0]=0;
        int mxidx=0;
        int ans=1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                
                if((nums[j]%nums[i]==0)&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    idx[i]=j;
                    
                    if(dp[i]>ans)
                    {
                        ans=dp[i];
                        mxidx=i;
                    }
                    
                }
                
            }
        }
        
        vector<int>temp;
        temp.push_back(nums[mxidx]);
        ans--;
        while(ans>0)
        {
            mxidx=idx[mxidx];
            temp.push_back(nums[mxidx]);
            ans--;
        }
        // cout<<mxidx<<endl;
        // for(auto k:idx)
        // {
        //     cout<<k<<" ";
        // }
        // cout<<endl;
        //  for(auto k:dp)
        // {
        //     cout<<k<<" ";
        // }
        
        return temp;
        
    }
};