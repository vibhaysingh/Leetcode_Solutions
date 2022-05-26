class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<int>v(n);
        
        v[0]=nums[0];
        
        for(int i=1;i<n;i++){
            
            v[i] = nums[i]*v[i-1];
        }
        
        int p = 1;
        
        for(int i=n-1;i>0;i--){
            
            v[i] = v[i-1]*p;
            p = p * nums[i];
        }
        
        v[0] = p;
        // for(auto k:v)cout<<k<<" ";
        
        return v;
        
    }
};