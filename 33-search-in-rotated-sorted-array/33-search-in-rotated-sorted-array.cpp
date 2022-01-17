class Solution {
public:
    int search(vector<int>& v, int t) {
        
        int n=v.size();
        
        // 6 7 1 2 3 4 5
        
        
        int l=0;
        int r=n-1;
        
        while(l<=r)
        {
            int m=(l+r)/2;
            
            if(v[m]==t)
                return m;
            
            else if( v[m]>v[r]) // mid element 
            {
                
                if(t < v[m] && t>=v[l] )
                    r=m-1;
                else
                    l=m+1;
                
                
            }
            else if(v[l]>v[m])
            {
                
                
                 if(t > v[m] && t<=v[r] )
                      l=m+1;
                else
                  r=m-1;
            }
            else /// no rotation
            {
                if(t<v[m])
                    r=m-1;
                else
                    l=m+1;
            }
        }
        
        return -1;
        
    }
};