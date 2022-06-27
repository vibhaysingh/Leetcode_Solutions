class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        // logic
        
        // we will keep track of no of subsequeces with common difference (d) end at current 
        // element
        // but how 
        // we will keep a map for every element to do this where key will be common diff
        // and value will be its count <cd,cnt>
        
        unordered_map< long long int,long long int>mp[n];
        
        int ans=0;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long  long cd = (long)nums[i]-nums[j];
              
                
                mp[i][cd]++;
                
                if(mp[j].find(cd)!=mp[j].end())
                {
                    int freq=mp[j][cd];
                    mp[i][cd]+=freq;
                    ans+=freq;
                }
            }
        }
        
        return ans;
        
        
        
    }
};