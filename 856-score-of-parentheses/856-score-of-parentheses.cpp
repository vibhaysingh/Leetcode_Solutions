class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int ans =0;
        int n =s.size();
        
        stack<pair<int,int>>st;
        
        st.push({-1,0}); // < idx of open bracket ,score >
        
        for(int i=0;i<n;i++){
            
            
            if(s[i]=='('){
                
                st.push({i,0});
            }
            else{
                
                int temp = st.top().second;
                int idx  = st.top().first;  
                
                int diff = i - idx;
                
                st.pop();
                
                if(diff==1){
                    
                    st.top().second++;
                }
                else{
                    
                    temp*=2;
                    st.top().second+=temp;;
                    
                }
                
                
            }
            
        }
        
        return st.top().second;
        
    }
};