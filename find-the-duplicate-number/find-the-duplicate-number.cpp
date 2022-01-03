class Solution {
public:
    
    bool isvalid(vector<int>& nums,int mid){
        int cnt=0;
        for(auto k:nums){
            if(k<=mid)cnt++;
        }
        
        return cnt>mid;
    }
    
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        // M-1 Sorting
        
//         sort(nums.begin(),nums.end());
        
//         for(int i=1;i<n;i++){
            
//             if(nums[i-1]==nums[i])
//                 return nums[i];
//         }
//         return -1;
        
        // M -2 Use unordered_set
        
//         unordered_set<int>st;
//         for(int i=0;i<n;i++){
            
//             if(st.count(nums[i]))
//                 return nums[i];
//             st.insert(nums[i]);
//         }
        
//         return -1;
        
    // M-3 Negative Indexing
        
    // Go to the idx = nums[i] & flip that nums[i] if at any idx if the nums[i]
    // is already flipped then that is repeating 
        
       // for(int i=0;i<n;i++){           
       //     int idx = abs(nums[i]);           
       //     if(nums[idx]<0) return idx;
       //     nums[idx]=-1*nums[idx];
       // }
       //  return -1;
        
      // M-4 binary search on answer
        
//         int low=1,high=n;
//         int ans=0;
//         while(low<=high){
            
//             int mid = (low+high)/2;
            
//             if(isvalid(nums,mid)){
                
//                 ans=mid;
//                 high=mid-1;
                
//             }else{
            
//               low=mid+1;  
//             }
//         }
        
//         return ans;
        
        // M-6 Linked List
        
        int slow= nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
            
        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
        
    }
};