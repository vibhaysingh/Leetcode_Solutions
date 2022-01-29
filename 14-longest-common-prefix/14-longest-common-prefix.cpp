class Solution {
public:
    
    
    string maxPrefix(string a, string b){
        
        string temp="";
        
        int l  = min ((int)a.size(),(int)b.size());
        
        for(int i=0;i<l;i++){
            
            if(a[i]==b[i]){
                temp+=a[i];
            }
            else{
                break;
            }
        }
        
        return temp;
        
    }
    
    
    string longestCommonPrefix(vector<string>& v) {
        
        int n = v.size();
        
        if(n==1) return v[0];
        
        string temp = maxPrefix(v[0],v[1]);
        
        for(int i=0;i<n;i++){
            
            temp = maxPrefix(temp,v[i]);
        }
        
        return temp;
        
    }
};