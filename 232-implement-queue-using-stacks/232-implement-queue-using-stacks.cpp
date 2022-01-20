class MyQueue {
public:
    MyQueue() {
        
    }
    
    stack<int>temp;
    stack<int>main;
    
    void push(int x) {
        
       
        
        while(!main.empty()){
            
            temp.push(main.top());
            main.pop();
        }
        
        temp.push(x);
        
        while(!temp.empty()){
            main.push(temp.top());
            temp.pop();
        }
        
        
    }
    
    int pop() {
        
        int x = main.top();
        main.pop();
        return x;
        
    }
    
    int peek() {
        
        return main.top();        
    }
    
    bool empty() {
        
        return (main.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */