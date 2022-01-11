class Solution {
public:
    
    vector<vector<int>>ans;
    
    void solver(vector<int>& nums,int idx,vector<int>&temp){
        
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[idx]); // le liya
        solver(nums,idx+1,temp);
        temp.pop_back(); // nhi liya
        solver(nums,idx+1,temp);
        
        
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // ans.clear();
        vector<int>temp;
        
        solver(nums,0,temp);
        
        return ans;
        
    }
};