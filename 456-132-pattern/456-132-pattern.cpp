class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        
        int second = INT_MIN; // will store (2) in 132 pattern
        stack<int>st; // will store (3) int 132 pattern
        
        for(int i=nums.size()-1;i>=0;i--){
            
            if(nums[i]<second) // (1) found in 132 pattern
                return true;
            
            while(!st.empty()&& nums[i]>st.top()){
                second = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
        
    }
};