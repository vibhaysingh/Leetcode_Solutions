class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        
        stack<char>char_st;
        stack<int>idx_st;
        
        idx_st.push(-1); // assume -1 is problem cuasing index
        
        int ans =0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='('){
                
                char_st.push(s[i]);
                
                idx_st.push(i); // assume i is problem causing index if its pair is not 
                // found in further string
                
            }else{
                
                
                if(!char_st.empty() && char_st.top()=='('){
                    
                    // cout<<idx_st.size()<<endl;
                    
                    char_st.pop();
                    idx_st.pop();
                    
                    ans = max(ans,i-idx_st.top());
                    
                    
                }
                else{
                    
                    idx_st.push(i);
                }
                
            }
        }
        
       return ans; 
    }
};