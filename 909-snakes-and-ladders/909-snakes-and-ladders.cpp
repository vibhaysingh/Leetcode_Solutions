class Solution {
public:
    
    vector<int> nextcordinate(int val,int n){
        
        int x = (val-1)/n;
        int y = (val-1)%n;
        
        if(x%2==1)
            y=n-1-y;
        x=n-1-x;
        return {x,y};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n  = board.size();
        int r=n;
        queue<int>q;        
        q.push(1);
        
        int moves=0;
        
        while(!q.empty()){
            
            int l= q.size();
            while(l--){
                
                int x = q.front();
                q.pop();
                
                if(x==r*r) return moves;
                
                for(int i=1;i<=6;i++){
                    
                    int nextval = x+i;
                    
                    if(nextval>r*r) break;
                    
                    auto v = nextcordinate(nextval,n);
                    
                    if(board[v[0]][v[1]]!=-1){
                        nextval = board[v[0]][v[1]];
                    }
                    
                    if(board[v[0]][v[1]]!=r*r+1){
                        board[v[0]][v[1]]=r*r+1;
                        q.push(nextval);
                    }
                }
            }
            moves++;
        }
        
       return -1; 
        
    }
};