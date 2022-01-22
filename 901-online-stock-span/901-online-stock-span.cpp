class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    stack<pair<int,int>>st;
    int idx =-1;
    int next(int price) {
        
        idx++;
        
        while(!st.empty()&&st.top().first <=price){
            st.pop();
        }
        
        int ans  = -1;
        
        if(st.empty()){
            
            ans = idx+1;            
            st.push({price,idx});
            
        }
        else{
            
            ans = idx-st.top().second;
             st.push({price,idx});
        }
        
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */