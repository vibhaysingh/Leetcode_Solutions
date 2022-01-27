class CustomStack {
public:
    
    vector<int>st,inc;
    int maxSize;
    
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        
        if(st.size() == maxSize) return;
        
        st.push_back(x);
        inc.push_back(0);
        
        return;
        
        
    }
    
    int pop() {
        
        int i  = st.size()-1;
        
        if(i<0) return -1;
        
        int incr = inc[i];
        
        if(i>0)
            inc[i-1]+=inc[i];
        
       
        int ans = st.back();
        st.pop_back();
        inc.pop_back();
        
        return ans+incr;
        
        
        
        
    }
    
    void increment(int k, int val) {
        
        // if(st.empty()) return;
        
        int i = min(k,(int)st.size())-1;
        if(i>=0)
        inc[i]+=val;
        
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */