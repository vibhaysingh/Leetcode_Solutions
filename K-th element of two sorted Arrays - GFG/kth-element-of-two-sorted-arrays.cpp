// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    int kthElement(int A[], int B[], int n, int m, int k)
    {
        
        // assume n is smaller
        
        if(n > m){
            return kthElement( B,  A,  m,  n,  k);
        }
        
        // ab n chhota m se 100%
        
        int low = -1;
        int high = n-1;
        
        while(low<=high){
            
             
                          
            int i = (low+high)/2; 
            
            int j = k - i-2;
            
            if(j<-1){
                high = i-1;
                continue;
            }
            
             if (j >= m) {
             low = i + 1;
           continue;
           }
            
            
            int Aleft = i>=0 ? A[i] : INT_MIN;
            int Aright = (i+1) < n ? A[i+1] : INT_MAX;
            int Bleft = j>=0 ? B[j] : INT_MIN;
            int Bright = (j+1)<m ? B[j+1] : INT_MAX;
            
            // check validity
            
            if(Aleft<=Bright && Bleft<=Aright){
                
                return max(Aleft,Bleft);
            }
            else if(Aleft>Bright){
                high = i-1;
            }
            else{
                low = i+1;
            }
            
            
            
            
        }
        
        return -1;
        
    }
};


// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends