class Solution {
public:
    int findMin(vector<int>& v) {
        
        int n= v.size();
        
        int low = 0,high=n-1;
        
        if(v[0]<=v[n-1]) return v[0];
        
        while(low<=high){
            
            int mid = (low+high)/2;
            
            int prev = (mid-1+n)%n;
            int next =  (mid+1)%n;
            
            if(v[prev]>=v[mid] && v[mid]<=v[next])
                return v[mid];
            
            
            if(v[0]<=v[mid]){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return -1;
    }
};