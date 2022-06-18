// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
int dp[101][101];
class Solution{
  public:
  
     bool solver(string &a,string&b,string &c,int n,int m,int l){
        
        
        if( l==0) return true;
        
        // if(n==0||l==0||m==0) return false;
        
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        bool f= false;
        
       // cout<<n<<" "<<m<<" "<<l<<endl;
        
        if(n>0&&c[l-1]==a[n-1]){
            
            f= solver(a,b,c,n-1,m,l-1);
        }
        if(m>0&&c[l-1]==b[m-1]){
            f= (f||solver(a,b,c,n,m-1,l-1));
       }
        
        return dp[n][m]=f;
    }
    /*You are required to complete this method */
    bool isInterleave(string s1, string s2, string s3) 
    {
        //Your c  int n = s1.size();
        int n = s1.size();
        int m  = s2.size();
        int l = s3.size();
        
        memset(dp,-1,sizeof dp);
        return solver(s1,s2,s3,n,m,l);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends