class CustomStack {
public:
    
    vector<int>v;
    int n;
    
    CustomStack(int maxSize) {
        
        n= maxSize;
    }
    
    void push(int x) {
        
        if(v.size()==n) return;
        
        v.push_back(x*1000000);
        
    }
    
    int pop() {
        
        int i = v.size()-1;
        
        if(i<0) return -1;
        
        int ans=0;
        int incr = (v.back()%1000000);
        int num = v.back()/1000000;
        
            if(i>0){
            v[i-1]+=incr;
            }
        
        
        ans = incr+num;
        
        v.pop_back();
        
        return ans;
            
        
        
    }
    
    void increment(int k, int val) {
        
        int i = min(k,(int) v.size())-1;
        
        if(i>=0){
            
            v[i]+=val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */