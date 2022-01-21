class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        
        // stack<char>char_st;
        stack<int>idx_st;
        
        idx_st.push(-1); 
        
        int ans =0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='('){
                
               
                
                idx_st.push(i); 
                
            }else{
                                    idx_st.pop();

                
                  if(idx_st.empty()){
                      idx_st.push(i);
                      continue;
                  }
                    
                    
                    
                    ans = max(ans,i-idx_st.top()); 
                
                
                
            }
        }
        
       return ans; 
    }
};