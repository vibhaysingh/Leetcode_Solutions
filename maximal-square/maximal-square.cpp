int dp[305][305];

class Solution {
public:
    
    int solver(int i,int j,vector<vector<char>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        if(i>=n||j>=m||mat[i][j]=='0')
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = 1+min({solver(i+1,j,mat),solver(i+1,j+1,mat),solver(i,j+1,mat)});
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        memset(dp,-1,sizeof dp);
        
        int ans =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='1')
                {
                    int temp= solver(i,j,mat);
                    ans = max(ans,temp);
                }
            }
        }
        
        return ans*ans;
    }
};