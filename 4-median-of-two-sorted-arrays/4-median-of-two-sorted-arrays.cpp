class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        cout<<fixed<<setprecision(5);
        int n = A.size();
        int m = B.size();
        
        double ans = 0.0;
        if(n>m){
            A.swap(B);
            swap(n,m);
        }
        
       
        
        // now nums1 is smaller than nums2
        
        
        
        int low = 0,high = n-1;
        int ttl = (m+n)/2;
       
        
        while(1){
            
            
            
            // cout<<high<<" "<<low<<endl;
            
             
            int i;
            if(high<low) i=high;
            else                
            i = (low+high)/2; // index of last element of first partition in samll array
            int j = ttl - i-2; // index of last element of second partition in large array
            
            int Aleft = i>=0 ? A[i]:INT_MIN; // last element of first partitiom in samll array
            int Aright = (i+1)<n ? A[i+1]:INT_MAX; // first element of second partition in small array
            
            int Bleft = j>=0? B[j]:INT_MIN; // last element of first partitiom in large array
            int Bright = (j+1) < m ? B[j+1]:INT_MAX; // first element of second partition in large array
            
            // INT_MAX aur INT_MIN isliye assign kr rhe hai kyuki left to chhota rakhna hai right part se
            
            // if partition is ok then
            
            
            
            
            if(Aleft <= Bright && Bleft <= Aright){
                
                
                
                if((m+n)%2==1){
                    ans  = min(Aright,Bright);
                    
                    return ans;
                }
                else{
                    
                    ans = (max(Aleft,Bleft)+ min(Aright,Bright))/2.0;
                    
                    
                    return ans;
                }
            }
            else if(Aleft>Bright){
               
                high = i-1;
                 
                
            }
            else{
                
                low = i+1;
            }  
            
            // cout<<high<<" new"<<low<<endl;
            
        }
        
        
        
        
        return ans;
        
        
    }
};