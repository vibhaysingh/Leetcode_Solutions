    class trie{

    public:

    bool isEnd;
    trie* child[26];
    int cnt;

    trie(){

        isEnd  = false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        cnt=0;
    }
};

class Solution {
public:
    


void addWord(trie* root, string &s){

    for(auto c:s){

        int idx = c-'a';

        if(root->child[idx]==NULL){

            root->child[idx]= new trie();
        }

        root = root->child[idx];
    }

    root->isEnd = true;   
    root->cnt = root->cnt +1;
}
    
    
vector<vector<bool>>vis;
vector<string>ans;


void dfs(trie* root, vector<vector<char>>& mat,string &curr,int i,int j){
    int n = mat.size();
    int m = mat[0].size();

    if(root->isEnd){

        ans.push_back(curr);
        // cout<<root->cnt<<endl;
        root->cnt-=1;
        if(root->cnt==0)
        root->isEnd = false;
    }

    if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) return;

    int idx = mat[i][j]- 'a';

    if(root->child[idx]){

        vis[i][j] = true;
        curr+=mat[i][j];

        dfs(root->child[idx],mat,curr,i+1,j);
        dfs(root->child[idx],mat,curr,i-1,j);
        dfs(root->child[idx],mat,curr,i,j+1);
        dfs(root->child[idx],mat,curr,i,j-1);
        // dfs(root->child[idx],mat,curr,i+1,j+1);
        // dfs(root->child[idx],mat,curr,i-1,j-1);
        // dfs(root->child[idx],mat,curr,i+1,j-1);
        // dfs(root->child[idx],mat,curr,i-1,j+1);

        vis[i][j]=false;
        curr.pop_back();
    }
   
}
    
    
    vector<string> findWords(vector<vector<char>>& mat, vector<string>& words) {
        
         int n = mat.size();
    int m = mat[0].size();

    vis.assign(n,vector<bool>(m,false));

    ans.clear();

    trie* root = new trie();
    for(auto k:words){
      
      addWord(root,k);
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            string curr="";
            dfs(root,mat,curr,i,j);
        }
    }

   

    return ans;
        
    }
};