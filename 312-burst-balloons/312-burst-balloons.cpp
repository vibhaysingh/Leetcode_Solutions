
int dp[502][502];
class Solution {
public:
    
  int solver(int i,int j,vector<int>&v){
        
        if(i>j) return 0;
     
     if(dp[i][j]!=-1) return dp[i][j];
        
       int temp = INT_MIN;
        
        for(int k=i;k<=j;k++){
            
            int x = (v[i-1]*v[k]*v[j+1]) + solver(i,k-1,v) + solver(k+1,j,v);
            
            temp = max(temp,x);
        }
        
        return dp[i][j]=temp;
    }
    
    int maxCoins(vector<int>& v) {
        
        int n = v.size();
        v.push_back(1);
        v.insert(v.begin(),1);
        
        memset(dp,0,sizeof dp);
        
        for(int i=n;i>=1;i--){
             
            for(int j=1;j<=n;j++){
                
                if(i>j) continue;
                  int temp = INT_MIN;
                 for(int k=i;k<=j;k++){
            
            int x = (v[i-1]*v[k]*v[j+1]) + dp[i][k-1] + dp[k+1][j];
            
            temp = max(temp,x);
        }
        
          dp[i][j]=temp;
                
            }
            
        }
        
        return dp[1][n];
        
    }
};