// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

int dp[10005];
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    int solver(int n,int x,int y,int z){
        
        if(n==0) return 0;
       
        
        int ans=INT_MIN;
        
        if(dp[n]!=-1) return dp[n];
        
        if(x<=n){
            ans = max(ans,solver(n-x,x,y,z));
        }
        if(y<=n){
            ans = max(ans,solver(n-y,x,y,z));
        }
        if(z<=n){
            ans = max(ans,solver(n-z,x,y,z));
        }
        
        return dp[n]=1+ans;
        
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp,-1,sizeof dp);
        int ans = solver(n,x,y,z);
        
        // cout<<ans<<endl;
        // cout<<INT_MIN<<endl;
        
        if(ans<0) return 0;
        else
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends