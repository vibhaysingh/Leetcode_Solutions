class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        
        vector< vector<int >>ra (10,vector<int>(10,0));
        vector<vector<int>>ca (10,vector<int>(10,0));
        vector<vector<int>>ma (10,vector<int>(10,0));
        
        // cout<<r[0][0]<<endl;
        // return 0;
        
      
        int n = b.size();
        int m = b[0].size();
        
        for(int i=0;i<9;i++){
            
            for(int j=0;j<9;j++){
                
                if(b[i][j]=='.')continue;
                
                int x = (b[i][j]-'0');
                
                int r=i/3,c=j/3;
                
                int no = (3*r)+c;
                
                if(ra[i][x]==1||ca[j][x]==1||ma[no][x]==1){
                    
                    
                    // cout<<i<<" "<<j<<" "<<x<<" "<<no<<endl;
                    // if(ma[no][x])cout<<"hi";
                    return false;
                } 
                    
                ra[i][x]=1;
                ca[j][x]=1;
                ma[no][x]=1;
                
            }
        }
        
        return true;
        
        
    }
};