class Solution {
public:
    
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        
    bool valid(int i,int j,int n,int m){
        
         if(i<0||j<0||i>=n||j>=m) return false;
        return true;
    }
    
    bool dfs(int i,int j,vector<vector<char>>& b, string &word,int idx){
        
        int n = b.size();
        int m = b[0].size();
        
        if(idx==word.size()) return true;
        
        // if(b[i][j]!=word[idx]) return false;
        
        char c = b[i][j];
        b[i][j]='.';
        
        for(int k=0;k<4;k++){
            
            int x = i+dir[k][0];
            int y = j+dir[k][1];
            
            if(valid(x,y,n,m)&& b[x][y]==word[idx] && dfs(x,y,b,word,idx+1)) return true;
        }
        
        b[i][j]=c;
        
        return false;
        
        
    }
    
    bool exist(vector<vector<char>>& b, string word) {
        
        int n = b.size();
        int m = b[0].size();
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                int idx=0;
                if(b[i][j]==word[0]&&dfs(i,j,b,word,1)) return true;
            }
        }
        
        return false;
    }
};