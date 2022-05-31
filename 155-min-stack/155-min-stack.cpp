class MinStack {
public:
    MinStack() {
        
    }
    
    long long int mn;
    stack<long long >st;
    
    void push(int val) {
        
      if(st.empty()){
          mn = val;
          st.push(val);
      }
        else if(val>=mn){
            st.push(val);
        }
        else{
            st.push(2LL*val-mn);
            mn = val;
        }
        
    }
    
    void pop() {
        
        if(st.top()<mn){
         
             mn = 2*mn - st.top();
        }
       
        
        st.pop();
        
        
    }
    
    int top() {
        
        if(st.top()<mn) return mn;
        
        return st.top();
        
    }
    
    int getMin() {
        
        return mn;
        
    }
};




        

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */