class RandomizedSet {
public:
    
    unordered_map<int,int>mp;
    vector<int>v;
    
    RandomizedSet() {
       
        
    }
    
    
    
    bool insert(int val) {
        
        if(mp.find(val)==mp.end()){            
            v.push_back(val);            
            mp[val] = v.size()-1;
            return true;
        }else{
            return false;
        }
        
    }
    
    bool remove(int val) {
        
        if(mp.find(val)==mp.end())
            return false;
        // cout<<val<<endl;
        int idx=mp[val];
        int lastidx=v.size()-1;
        mp[v[lastidx]]=idx;        
        swap(v[idx],v[lastidx]);
        v.pop_back();
        // cout<<v.back()<<"back"<<endl;
        mp.erase(val);
        
        return true;
        
    }
    
    int getRandom() {
        
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */