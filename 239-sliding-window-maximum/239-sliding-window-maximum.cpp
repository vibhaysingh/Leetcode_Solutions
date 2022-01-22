class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();        
        
        // deque will store the max element of the window in front
        // flush the indices which are out of window
        
        deque<int>dq;
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            
            
              /// check for invalid index in deque
            
               while(!dq.empty() && dq.front()<i-k+1)
                    dq.pop_front();
                
             // try to put max element of window to the front
                
                while(!dq.empty() && nums[dq.back()]<nums[i]){
                    dq.pop_back();
                }
            
            dq.push_back(i);
            
//             for(auto k :dq){
//                 cout<<nums[k]<<" ";
//             }
//             cout<<endl;
            
            if(i>=k-1)// make answer if atleast 1 window is processed
                ans.push_back(nums[dq.front()]);
                
                
            
        }
        
        return ans;
        
        
    }
};