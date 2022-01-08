class Solution {
public:
    int trap(vector<int>& ht) {
        
        int n = ht.size();
        
        int leftmax=ht[0];
        int rightmax= ht[n-1];
        int l= 1;
        int r = n-2;
        int ans=0;
        
        while(l<=r){
            
            if(leftmax>=rightmax){
                
                if(ht[r]>=rightmax){
                    rightmax = ht[r];
                }else{
                    ans+=rightmax - ht[r];
                }
                r--;
                
            }else{
                
                if(ht[l]>=leftmax){
                    leftmax=ht[l];
                }else{
                    ans+=leftmax-ht[l];
                }
                
               l++; 
            }
        }
        
        return ans;
        
    }
};