
int dp[105][105];

class Solution {
public:
    
//     int solver(int i,int j, vector<int>&cuts){
        
//         if(i>j){
//             return 0;
//         }
        
//         // cout<<i<<" "<<j<<endl;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int temp=INT_MAX;
        
//         for(int k=i;k<=j;k++){
            
//              int s = (cuts[j+1]-cuts[i-1]) + solver(i,k-1,cuts) + solver(k+1,j,cuts);
//             temp=min(temp,s);
//         }
        
//         return dp[i][j]=temp;
//     }
    
    
    int minCost(int n, vector<int>& cuts) {
        int l= cuts.size();
        memset(dp,0,sizeof dp);
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        
        for(int i=l;i>=1;i--){
            for(int j=1;j<=l;j++){
                
                if(i>j)continue;
                int temp=INT_MAX;
        
        for(int k=i;k<=j;k++){
            
             int s = (cuts[j+1]-cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
            temp=min(temp,s);
        }        
        dp[i][j]=temp;
        }
    }
        
        return dp[1][l];
    }
};