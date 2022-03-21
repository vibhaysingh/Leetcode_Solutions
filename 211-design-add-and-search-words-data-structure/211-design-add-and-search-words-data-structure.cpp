

struct trie{
    
    trie* child[26];
    bool isend=false;
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    trie* root = new trie();
    
    
    void addWord(string word) {
        
        trie* curr=root;
        
        for(char c:word){
            
            if(!curr->child[c-'a']){
                curr->child[c-'a']=new trie();
            }
            
            curr=curr->child[c-'a'];
        }
        
        curr->isend = true;
        
    }
    
    bool dfs(trie* curr,string &s,int idx){
        
        if(idx==s.size()) {
            return curr->isend;
        }
        
        
        if(s[idx]!='.'){
            
            
            if(curr->child[s[idx]-'a']==NULL) return false;
            
            if(dfs(curr->child[s[idx]-'a'],s,idx+1)) return true;
            
            return false;
            
        }
        else{
            
            
            for(char c='a';c<='z';c++){
                
                if(curr->child[c-'a']){
                    
                    if(dfs(curr->child[c-'a'],s,idx+1)) return true;
                }
            }
            
            return false;
            
        }
        
        return false;
        
    }
    
    bool search(string word) {
        
        
        return dfs(root,word,0);
        
        
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */