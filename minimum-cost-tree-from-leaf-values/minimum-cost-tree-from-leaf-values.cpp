
int dp[45][45];
class Solution {
public:
    
    int solver(int i,int j, vector<int>&arr)
    {
        
        if(i==j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int k,ans=INT_MAX;
        for(k=i;k<j;k++)
        {
            int temp = solver(i,k,arr)+solver(k+1,j,arr)+(*max_element(arr.begin()+i,arr.begin()+k+1))*(*max_element(arr.begin()+k+1,arr.begin()+j+1));
            
            ans = min(ans,temp);
        }
        
        return dp[i][j]=ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        memset(dp,-1,sizeof dp);
        return solver(0,n-1,arr);
    }
};