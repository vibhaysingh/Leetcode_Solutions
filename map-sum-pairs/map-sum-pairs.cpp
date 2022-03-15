

struct trie{
    
    trie* child[26]={0};
    
    
    int val=0;
    bool isend=false;
    
};


class MapSum {
public:
    MapSum() {
        
    }
    
    trie* root = new trie();
    unordered_map<string,int>mp;
    
    void insert(string key, int val) {
        
        trie* temp = root;
        
        bool f=false;
        int x;
        
        if(mp.count(key)){
            f=true;
            x=mp[key];
        }
        
        mp[key] =val;
        
        
        
        
        for(char c:key){
            
            if(!temp->child[c-'a']){                
                temp->child[c-'a']=new trie();
            }
            
            
            temp = temp->child[c-'a'];   
            
            if(!f)
            temp->val+=val;
            else{
                
                temp->val = temp->val-x + val;
            }
            
        }
        
    }
    
    int sum(string prefix) {
        
        int ans=0;
         trie* temp = root;
        
        for(char c:prefix){
            
            
            if(!temp->child[c-'a']) {
                ans=0;
                break;
            }
            
            temp = temp->child[c-'a'];
            ans = temp->val;
            
        }
        
        return ans;
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */