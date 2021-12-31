/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    vector<int>temp;
    
    void solver(int idx,vector<NestedInteger> &v){
        
       if(idx>=v.size())return;
        
        if(v[idx].isInteger()){
            
            temp.push_back(v[idx].getInteger());
            
            
        }else{
            
            vector <NestedInteger> x = v[idx].getList();
             solver(0,x);
            
        } 
        solver(idx+1,v);
    }
    
    
    NestedIterator(vector<NestedInteger> &v) {
        
        solver(0,v);
        
        
    }
    
    int i=0;
    
    int next() {
        
       return temp[i++];
    }
    
    bool hasNext() {
       return i<temp.size();
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */