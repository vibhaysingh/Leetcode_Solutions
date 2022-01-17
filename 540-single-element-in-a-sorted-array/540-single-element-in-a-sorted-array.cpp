class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1) return nums[0];
        int low = 1;
        int high= n-2;
        int mid;
        
        while(low<=high){
            
             mid = (low+high)/2;
            
            if(mid%2==0){
                
                if(nums[mid-1]==nums[mid]){ // left side equal
                    
                    high = mid-1;
                }
                else if(nums[mid]==nums[mid+1]){ // right side equal
                    
                    low = mid+1;
                }
                else{ // none of sides are equul then element is found
                    
                    return nums[mid];
                }
                
                
            }
            else{
                
                if(nums[mid-1]==nums[mid]){ // left side equal
                    
                     low = mid+1;
                    
                }
                else if(nums[mid]==nums[mid+1]){ // right side equal
                    
                   
                    high = mid-1;
                }
                else{ // none of sides are equul then element is found
                    
                    return nums[mid];
                }
            }
        }
        
        if(low>mid)                
     return nums[low];
        else
            return nums[high];
        
    }
};