// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
   public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    
	    vector<int>dp(arr,arr+n);
	    
	   // dp=arr;
	    
	   // for(int i=0;i<n;i++)cout<<dp[i]<<" ";
	   // cout<<endl;
	    
	    for(int i=1;i<n;i++){
	        
	        for(int j=0;j<i;j++){
	            
	            if(arr[i]>arr[j]){
	                
	               // if(i==3){
	               //     cout<<"here "<< dp[i]<<" "<<j<<endl;
	               // }
	                dp[i] = max(dp[i],(dp[j]+arr[i]));
	                
	               // cout<<"here "<< dp[i]<<" i "<<i<<" j "<<j<<endl;
	            }
	            
	        }
	    }
	   // cout<<endl;
	   //  for(int i=0;i<n;i++)cout<<dp[i]<<" ";
	    return *max_element(dp.begin(),dp.end());
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends