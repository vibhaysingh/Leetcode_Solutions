class Solution {
public:
    
    int solve(vector<int>& nums, int k){
        
        
         unordered_map<int,int>mp; 
        
        if(k==0) return 0;
       
        int l=0,r=0,diff=0,res=0;
        
        int n  = nums.size();
        
        while(r<n){
            
          mp[nums[r]]++;
            
            if(mp[nums[r]]==1) diff++;
            
            while(l<r && diff>k){
                
                mp[nums[l]]--;
                
                if(mp[nums[l]]==0) diff--;
                
                l++;
                
            }
            
            res+=(r-l+1);
           // cout<<res<<endl;
            r++;
            
        }
        
        return res;
    }
    
    
    
int subarraysWithKDistinct(vector<int>& nums, int k) {
        
            
        return solve(nums,k)-solve(nums,k-1);
        
    }
};