class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        // sweep line
        
        int n = nums.size();
        
        int * flip = new int[n+1];
        
        // int flip[n+1]={0};
        
        
        for(int i=0;i<n+1;i++){
            flip[i]=0;
            // cout<<flip[i]<<" ";
        }
        // cout<<endl;
        
       
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            if(i){
                flip[i]+=flip[i-1];
            }
            
            /// check flip condition
            
            if((nums[i]+  flip[i])%2==0){
                
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