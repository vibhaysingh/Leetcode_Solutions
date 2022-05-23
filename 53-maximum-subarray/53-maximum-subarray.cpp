class Solution {
public:
    
   long  solver(int l,int r,vector<int>&nums){
        
        if(l>r) return INT_MIN;
        
       long  int mid = (l+r)/2;
        
       long  int leftsum=0,rightsum=0;
        
        for(long int i=mid-1,currsum=0;i>=l;i--){
            
            currsum+=nums[i];
            leftsum=max(leftsum,currsum);
        }
        
        for(long int i=mid+1,currsum=0;i<=r;i++){
            
            currsum+=nums[i];
            rightsum = max(rightsum,currsum);
        }
        
        return max({leftsum+nums[mid]+rightsum, solver(l,mid-1,nums), solver(mid+1,r,nums)});
    }
    
    int maxSubArray(vector<int>& nums) {
        
        
        int n = nums.size();
        
        
        return solver(0,nums.size()-1,nums);
        
        
        
    }
};