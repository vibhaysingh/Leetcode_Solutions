class Solution {
public:
    
    vector<vector<int>>ans;
    
    void solver(int idx,int &sum,vector<int>& nums,int &target,vector<int>&temp){
        
        if(sum==target){
            ans.push_back(temp);
            return;
        }        
         if(idx>=nums.size()){
            return;
        }
        
                
        sum+=nums[idx];
        temp.push_back(nums[idx]);
        
        if(sum<=target){
            
            solver(idx,sum,nums,target,temp);
             sum-=nums[idx];
            // cout<<sum<<endl;
            temp.pop_back();
            solver(idx+1,sum,nums,target,temp);
        }else{
            
            sum-=nums[idx];
            // cout<<sum<<endl;
            temp.pop_back();
            solver(idx+1,sum,nums,target,temp);
        }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        
        vector<int>temp;
        int sum = 0;
        solver(0,sum,cand,target,temp);
        
        return ans;
        
    }
};