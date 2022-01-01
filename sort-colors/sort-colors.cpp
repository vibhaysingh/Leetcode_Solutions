class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int left=0,right=n-1,mid=0;
        
       while(mid<=right){
           
           if(nums[mid]==0){
               swap(nums[left],nums[mid]);
               left++; 
               mid++;
           }
           else if(nums[mid]==2){
               swap(nums[right],nums[mid]);
               right--;
              
           }
           else{
               mid++;
           }
       }
        
    }
};

