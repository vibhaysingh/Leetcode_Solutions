class Solution {
public:
    
    vector<vector<string>>ans;
    
    bool isvalid(int row,int col,vector<string>&v,int n){
        
        int r = row;
        int c = col;
        
        
        /// diagonally
        
        while(r>=0 && c>=0){
            
            if(v[r][c]=='Q') return false;
            
            r--;
            c--;            
        }
        
    r = row;
	c = col;
        
	while (r >= 0)
	{
		if (v[r][c] == 'Q')
			return false;
		r--;

	}
        
	r = row;
	c = col;
        
	while (c < n && r >= 0)
	{

		if (v[r][c] == 'Q')
			return false;
        
		r--;
		c++;
	}  
        
           return true;    
        
    }
    
    
    
    void solver(int row,vector<string>&v,int n){
                
        if(row==n){
            
            ans.push_back(v);
            return ;
        }
        
        for(int col=0;col<n;col++){
            
            if(isvalid(row,col,v,n)){
                
                v[row][col]= 'Q';
                
                solver(row+1,v,n);
                
                v[row][col]= '.';
                
                
            }
        }        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        
       vector<string>v(n);
       
        string x(n,'.');
        
        for(int i=0;i<n;i++){
            v[i]=x;
        }       
        solver(0,v,n);
        
        return ans;
        
    }
};