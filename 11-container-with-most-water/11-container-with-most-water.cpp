class Solution {
public:
    int maxArea(vector<int>& h) {
        
        int n  = h.size();
        
        
        
        int i=0,j=n-1;
        
        int ans=0;
        
        while(i<=j){
           
            if(h[i]<=h[j]){
                
                ans = max(ans,h[i]*(j-i));
                i++;
            }
            else{
                ans = max(ans,h[j]*(j-i));
                j--;
            }
            
        }
        
        return ans;
        
        
    }
};