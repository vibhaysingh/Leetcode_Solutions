class Solution {
public:
    
    int maxAreahistogram(vector<int>v){
        
        int n = v.size();
        
        stack<int>st;
        int ans=0;
        
        for(int i=0;i<=n;i++){
            
            
            while(!st.empty() &&( i==n || v[st.top()]>v[i])){
                
                int height = v[st.top()];
                
                st.pop();
                
                int width=0;
                
                if(st.empty())
                    width =i;
                else{
                    width = i-st.top()-1;
                }
                
                ans = max(ans,height*width);
            }
            
            st.push(i);
            
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int>v(m,0);
        int ans = 0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(mat[i][j]=='0')
                    v[j]=0;
                else{
                   v[j]+=1; 
                    
                }
                
            }
            int x  =maxAreahistogram(v);
//             cout<<x<<endl;
//             for(auto k:v){
//                 cout<<k<<" ";
                
//             }
//             cout<<endl;
            ans = max(ans,x);
            
        }
        
        return ans;
        
    }
};