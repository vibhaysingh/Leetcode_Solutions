struct node{
    
    node* child[26]={0};
    bool isEnd = false;

};
class Trie {
public:
    
    node* root = new node();
    
    Trie() {
        
    }
    
    void insert(string word) {
        
        
        node* t = root;
        
        for(auto k:word){
            
            if(t->child[k-'a']==NULL){
               
               t->child[k-'a'] = new node();
                
                t= t->child[k-'a'];
                
            }
            else{
               t= t->child[k-'a'];
            }
            
        }
        
        t->isEnd = true;
        
    }
    
    bool search(string word) {
       
         node* t = root;
        
        for(auto k:word){
            
             if(t->child[k-'a']==NULL){
               
               return false;
                
            }
            else{
                t= t->child[k-'a'];
            }
            
        }
        
        return t->isEnd;
        
        
    }
    
    bool startsWith(string words) {
        
        node* t = root;
        
        for(auto k:words){
            
             if(t->child[k-'a']==NULL){
               
               return false;
                
            }
            else{
                t= t->child[k-'a'];
            }
            
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */