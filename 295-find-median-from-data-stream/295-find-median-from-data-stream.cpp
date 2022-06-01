class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    priority_queue<int>mxh;
    priority_queue<int,vector<int>,greater<int>>mnh;
    void addNum(int num) {
        
        mnh.push(num);
        
        
        // max heap ki top value choti rhni chahiye min heap ki top value se
        
        if((int)mxh.size() >0 && mxh.top()>mnh.top()){
            
            mxh.push(mnh.top());
            mnh.pop();
            
        }
      
        if((int)mnh.size()-(int)mxh.size()>1){
              
            mxh.push(mnh.top());
            mnh.pop();
            
        }
        
        
         if((int)mxh.size()-(int)mnh.size()>1){
             
            mnh.push(mxh.top());
            mxh.pop();
            
        }
        
//         if(num==-4){
//             cout<<mnh.top()<<" "<<mxh.top()<<endl;
//         }
     
        
    }
    
    double findMedian() {
        
        double ans=0.0;
        
        if((int)mnh.size()==(int)mxh.size()){
            
            ans = (mnh.top()+mxh.top())/2.0;
            
        }
        else if((int)mnh.size()>(int)mxh.size()){
            ans=mnh.top();
        }
        else{
            ans=mxh.top();
        }
        
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */