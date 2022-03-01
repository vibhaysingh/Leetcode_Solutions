class Solution {
public:
    
    int dx[8]={1,0,0,-1,1,-1,1,-1};
    int dy[8]={0,1,-1,0,1,1,-1,-1};
    
    bool isValid(int &i,int &j,int &n,int &m){

    if(i<0 || i>=n || j<0 || j>=m) return false;

    return true;
    }
    
    int ttln(int i,int j,vector<vector<int>>& b){
        
        int cnt=0;
         int n = b.size();
        int m = b[0].size();
        
         for(int d=0;d<8;d++){

             
             int x = i + dx[d];
             int y = j + dy[d];

             if(isValid(x,y,n,m)&&(b[x][y]==1||b[x][y]==3)) {
                 cnt++;                
             }
              // if(cnt>3) break;
         }
        
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& b) {
        
        
//            original --- new --- keyword
//              0          0         0
//              0          1         2
//              1          0         1
//              1          1         3  
        
        int n = b.size();
        int m = b[0].size();
        
       for(int i=0;i<n;i++){
           
           for(int j=0;j<m;j++){
               
               int cnt= ttln(i,j,b);
               
               if(i==2&&j==2){
                   cout<<"cnt"<<cnt<<endl;
               }
               
               if(b[i][j]==1){
                   
                   if(cnt==2||cnt==3){
                       b[i][j]=3;
                   }
               }
               else{
                   
                   if(cnt==3){
                       b[i][j]=2;
                   }
               }
               
                
           }
       } 
        
         
//         for(int i=0;i<n;i++){
            
//             for(int j=0;j<m;j++){
                
//                 cout<<b[i][j]<<" ";
//             }
            
//             cout<<endl;
//         }
        
        
        
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(b[i][j]==2||b[i][j]==3){
                    b[i][j]=1;
                }
                else{
                    b[i][j]=0;
                }
            }
        }
            
        
    }
};