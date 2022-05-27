class Solution {
public:
    string minWindow(string s, string t) {
        
        
        int n = s.size();
        int m = t.size();
        
        int i=0,j=0,count=0;
        
     
        
        int f[256]={0};
        
        
        for(int i=0;i<t.size();i++){           
            f[t[i]-'A']++;          
        }
        
       long long int l=INT_MIN,r=INT_MAX;
        
        
        while(j<n){
            
            if( f[s[j]-'A']>0){
                count++;
               
            }
             f[s[j]-'A']--;
            
            if(count==m && (j-i)<(r-l)){
                 
                l=i,r=j;
                
               
            }
            
            while(i<=j && count==m){
                
            if(count==m && (j-i)<(r-l)){
                
              
               
                l=i,r=j;
                
            }
            
                f[s[i]-'A']++;
                if(f[s[i]-'A']>0){
                    
                    count--;
                }
                i++;
                
                
            }

            j++;
            
        }
        
        string ans="";
        
        if(l==INT_MIN) return ans;
        
        for(int i=l;i<=r;i++){
            ans+=s[i];
        }
        
        return ans;
    }
};