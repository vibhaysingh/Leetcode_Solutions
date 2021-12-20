class Solution {
public:
    
    bool solver(int idx, int currSum , int reqSum, int k,vector<int>& nums, vector<int>&taken)
    {
        int n = nums.size();
        
        if(k==0) return true;
        
        if(currSum > reqSum)
            return false;
        
        if(currSum==reqSum)
            return solver(0,0,reqSum,k-1,nums,taken);
        
        for(int i=idx;i<n;i++)
        {
            if(!taken[i])
            {
                taken[i]=1;                
                if(solver(i+1,currSum+nums[i],reqSum,k,nums,taken))
                     return true;
                taken[i]=0;
                
            }
        }
        
        return false;
        
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum%k) return false;
        
        int reqSum = sum/k;
        int n = nums.size();
        vector<int>taken(n,0);
        
        return solver(0,0,reqSum,k,nums,taken);
        
    }
};