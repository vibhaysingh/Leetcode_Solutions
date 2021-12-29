class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

     // Time O(n logn)  space O(n) 
        
        int n = nums.size();        
//         vector<int>ans;
//         ans.push_back(nums[0]);
        
//         for(int i=1;i<n;i++){
            
//             if(ans.back()>=nums[i]){
                
//                 auto k = lower_bound(ans.begin(),ans.end(),nums[i]);
//                 *k=nums[i];
                
//             }else{
//                 ans.push_back(nums[i]);
//             }
//         }
        
//         return ans.size()>=3;
        
        int first=INT_MAX,second=INT_MAX;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]<=first){
                first=nums[i];
            }
            else if(nums[i]<=second){
                second=nums[i];
            }
            else{
                // cout<<nums[i]<<endl;
                return true;
            }
        }
        
        return false;
        
        
    }
};

/// 1 2 -1 4