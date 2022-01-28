class Solution {
public:
    
     int le=0,ri=0;
     int maxLen=0;
    
    void extend(int l,int r,string &s){
        
        int n = s.size();
        
        // cout<<l<<r<<endl;
        while(l>=0 && r < n && s[l]==s[r]){
            
            if(r-l+1>maxLen){
            le = l;
            ri = r;
            maxLen = r-l+1;
        }
            
            l--;
            r++;
            
            
        }
        
        // cout<<le<<ri<<endl;
        
        
        
        
    }
    
    string longestPalindrome(string s) {
        
       
        
        int n = s.size();
        
        if(n<2) return s;
        
        for(int i=0;i<n-1;i++){
            
            extend(i,i,s);
            extend(i,i+1,s);
            
        }
        
        
        string ans="";
        
        for(int i=le;i<=ri;i++){
            
            ans+=s[i];
        }
        
        return ans;
    }
    
    
};