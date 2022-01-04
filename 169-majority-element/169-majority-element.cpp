class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidate =nums[0];
        int votes =1;
        
        for(int i=1;i<nums.size();i++){
            
            if(votes==0){
                candidate =nums[i];
                votes=1;
            }
            else if(candidate==nums[i]){
                votes++;
            }else if(candidate!=nums[i]){
                votes--;
            }
        }
        
        
        
        
            return candidate;
        
        
    }
};