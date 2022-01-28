class Solution {
public:
    
    int precedance(char op){
        
        if(op=='+'||op=='-') 
            return 0;
        return 1;
    }
    
    int evaluate(int a, int b , char op){
        
        // cout<<op<<endl<<a<<b<<endl;;
        if(op=='+') return a+b;
        if(op=='-') return a-b;
        if(op=='*') return a*b;
        if(op=='/') return a/b;
        
        return 0;
    }
    
    int calculate(string s) {
        
        int n = s.size();
        stack<int>st;
        stack<char>op;
        
        int  num =0;
        
        for(int i=0;i<=n;i++){
            
            
            if(i<n && s[i]==' ')continue;
            
            if(i<n && isdigit(s[i])){
                
                num = num*10 + (s[i]-'0');
            }
            else{
                
                st.push(num);
                
                while(!op.empty() && (i==n or precedance(s[i])<=precedance(op.top()))){
                    
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    // cout<<evaluate(a,b,op.top())<<endl;
                    st.push(evaluate(b,a,op.top()));
                    op.pop();
                }
                
                if(i<n) op.push(s[i]);
                num=0;
            }
            
        }
        
        return st.top();
        
    }
};