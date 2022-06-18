// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    
    
    
    
vector<long long>dp;

Solution(){
    dp.resize(5005,-1);
}
    
    long long solve(int n,int k){
        
        
        if(n==0) return 0;
        
        if(n==1) return k;
        
        if(dp[n]!=-1) return dp[n];
        
        else if(n==2){
            
            return add(k,mul(k,k-1));
            
        }
        
        else{
            
           return dp[n]=add(mul(solve(n-1,k),k-1),mul(solve(n-2,k),k-1));
            
        }
        
        return 0;
        
    }
    
    int m = 1e9+7;
    
    long long add(long long a,long long b){
        
        long long c = (a%m+b%m)%m;
        return c;
    }
    
     long long mul(long long a,long long b){
        
        long long c = (a%m*b%m)%m;
        return c;
    }
    
    long long countWays(int n, int k){
        // code here
        
        // return solve(n,k);
        
        vector<long>dp(n+1,0);
        
        dp[1]=k;
        dp[2]=add(k,mul(k,k-1));
        
        for(int i=3;i<=n;i++){
            
            dp[i] = add(mul(dp[i-1],k-1),mul(dp[i-2],k-1));
        }
        
        return dp[n];
        
        
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends