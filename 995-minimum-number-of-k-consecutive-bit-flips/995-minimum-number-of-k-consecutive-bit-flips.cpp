class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        // sweep line
        
        int n = nums.size();
        
        vector<int>flip(n+1,0);
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            if(i){
                flip[i]+=flip[i-1];
            }
            
            /// check flip condition
            
            if((nums[i]==0 && flip[i]%2==0)||(nums[i]==1 && flip[i]%2==1)){
                
                ans++;
                flip[i]++;
                
                if(i+k>n) return -1;
                
                flip[i+k]--;
            }
        }
        
        return ans;
        
    }
};

// 0-->1 0 1
// 1-->0 1 0    