class Solution {
public:
    
    vector<vector<int>>ans;
    
    void solver(vector<int>& nums,int idx, vector<int>&temp, bool included){
        
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        
        if(idx==0){
            // temp.push_back(nums[idx]);
            solver(nums,idx+1,temp,true);
        }
        else if(idx>0 && nums[idx-1]!=nums[idx]){
            
             // temp.push_back(nums[idx]);
             solver(nums,idx+1,temp,true);
            
        }else if(idx>0 && nums[idx-1]==nums[idx] && included){
            
             // temp.push_back(nums[idx]);
             solver(nums,idx+1,temp,true);
        }
        
        if(!temp.empty())
        temp.pop_back();
        solver(nums,idx+1,temp,false);
        
        
        
       
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solver(nums,0,temp,true);
        return ans;
    }
};