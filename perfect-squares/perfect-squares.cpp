
int dp[10005][105];
class Solution {
public:
    
    int ans = INT_MAX;
        
    int solver(int n,vector<int>&sq,int cnt,int sum,int l)
    {
        
        if(l==0)
            return INT_MAX;
        
        if(sum==n)
        {
            // ans = min(ans,cnt);
            return 0;
        }  
        
        if(dp[n-sum][l]!=-1)
            return dp[n-sum][l];
                
        if(sq[l-1] + sum > n){
            return dp[n-sum][l]=solver(n,sq,cnt,sum,l-1);
        }
        else
        {
             dp[n-sum][l]=min(solver(n,sq,cnt,sum,l-1), // leave
             1+solver(n,sq,cnt+1,sum+sq[l-1],l));// take and again take
           
        }        
                 
        return dp[n-sum][l];
    }
    
    int numSquares(int n) {
                
        vector<int>sq;
        for(int i=1;i*i<=n;i++)
        {
            sq.push_back(i*i);
        }        
        memset(dp,-1,sizeof dp);
       
        int l =sq.size();
        return solver(n,sq,0,0,l);
        
        // return ans;
    }
};