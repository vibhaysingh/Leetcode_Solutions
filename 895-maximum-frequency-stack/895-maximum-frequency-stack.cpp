class FreqStack {
public:
    FreqStack() {
        
    }
    
    map<int,int>f;
    map<int,stack<int>>fs;
    
    int mxf=0;
    
    void push(int val) {
        
        f[val]++;
        
        
        int x= f[val];
        mxf = max(x,mxf);
        fs[x].push(val);
    }
    
    int pop() {
        
       int ans = fs[mxf].top(); 
        fs[mxf].pop();
        
        f[ans]--;
        
        if(fs[mxf].empty()) mxf--;
        
        return ans;
        
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */