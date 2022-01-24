class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        
        
        int n = ht.size();
        stack<int>st;
        
        int ans =0;
        
        for(int i=0;i<=n;i++){
            
            
            while(!st.empty() && (i==n || ht[st.top()]>ht[i])){
                
                int height = ht[st.top()];
                st.pop();
                
                int width=0;
                
                if(st.empty()){
                    width =i;
                }
                else{
                    width = i-st.top()-1;
                }
                
                ans = max(ans,height*width);
            }
            
            st.push(i);
            
        }
        
        return ans;
        
        
    }
};