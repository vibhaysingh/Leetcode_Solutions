class Solution {
public:
    int majorityElement(vector<int>& nums) {
  
        // M-1 Voting Algo
//         int candidate =nums[0];
//         int votes =1;        
//         for(int i=1;i<nums.size();i++){
            
//             if(votes==0){
//                 candidate =nums[i];
//                 votes=1;
//             }
//             else if(candidate==nums[i]){
//                 votes++;
//             }else if(candidate!=nums[i]){
//                 votes--;
//             }
//         }      
//             return candidate;
        
        // M-2 Bit Manipulation
        
        int candidate =0;
        int n = nums.size();
        
        for(int i=0;i<32;i++){
            
            int count=0; // count of ith bit in every number
            
            for(int j=0;j<n;j++){
                
                if((nums[j]>>i)&1)
                    count++;
            }
            
            if(count>n/2)
                candidate=(candidate |(1<<i));
            
            
        }
        
        return candidate;
        
        
    }
};