class MyCircularQueue {
public:
    
    vector<int>data;
    int l,r;
    int n;
    
    MyCircularQueue(int k) {
        
        data.resize(k);
        l=-1;
        r=-1;
        n=k;
        
    }
    
    bool enQueue(int value) {
        
        if(isFull()) return false;
        
         if(isEmpty()){
             l=0;
             r=0;
             data[r]=value;
             return true;
         }
         r = (r+1)%n;
         data[r]=value;
        return true;
        
        
    }
    
    bool deQueue() {
        
        if(isEmpty()) return false;
        
        if(l==r){
            l=-1;
            r=-1;
            return true;
        }
        
        l = (l+1)%n;
        
        return true;
        
    }
    
    int Front() {
        
         if(isEmpty()){
            return -1;
        }
        
        return data[l];
        
    }
    
    int Rear() {
        
        if(isEmpty()){
            return -1;
        }
        return data[r];
    }
    
    bool isEmpty() {
        
        return l==-1;
    }
    
    bool isFull() {
        
        return (r+1)%n == l;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */