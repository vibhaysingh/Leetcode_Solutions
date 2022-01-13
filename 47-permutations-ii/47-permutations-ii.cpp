class Solution {
public:
    
    
    vector<vector<int>>ans;
    vector<int>used;
    vector<int>temp;
    
    
    void solver(int idx,vector<int>& nums,vector<int>&used,vector<int>&temp){
        
        
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(used[i]||(i>0 && nums[i-1]==nums[i] && !used[i-1])) continue;
                
                used[i]=1;
                temp.push_back(nums[i]);
                solver(i+1,nums,used,temp);
                temp.pop_back();
                used[i]=0;
            
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        used.resize(nums.size(),0);
        
        sort(nums.begin(),nums.end());
        
        solver(0,nums,used,temp);
        
        return ans;
        
    }
};