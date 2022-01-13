class Solution {
public:
    
    vector<vector<int>>ans;
    
    void solver(vector<int>& nums,int idx,vector<int>&temp,bool included,int &curr_sum,int &target){
        
        
        if(curr_sum>target) return;
        
        if(curr_sum==target){
            ans.push_back(temp);
            return;
        }        
        if(idx>=nums.size()){
            return;
        }
        
        curr_sum+=nums[idx];
        temp.push_back(nums[idx]);
        
        if(idx==0){            
            solver(nums,idx+1,temp,true,curr_sum,target);
        }
        else if(idx>0 && nums[idx-1]!=nums[idx]){             
             solver(nums,idx+1,temp,true,curr_sum,target); 
            
        }else if(idx>0 && nums[idx-1]==nums[idx] && included){ 
            
             solver(nums,idx+1,temp,true,curr_sum,target);
        }
        
        temp.pop_back();
        curr_sum-=nums[idx];
        
        solver(nums,idx+1,temp,false,curr_sum,target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        vector<int>temp;
        int curr_sum=0;
        solver(nums,0,temp,true,curr_sum,target);
        return ans;
        
    }
};