class Solution {
public:
    
    string solver(string s){
        
        int n = s.size();
        
        if(n==1){
            
           s+=s;
            return s;
        }
        
        string ans="";
        int cnt=0;
        for(int i=0;i<n-1;i++){
            
            if(s[i]==s[i+1]) cnt++;
            
           else  if(s[i]!=s[i+1]){
               cnt++;                
                ans+=to_string(cnt)+s[i];
               cnt=0;
            }
        }
  
        cnt++;
       ans+=to_string(cnt)+s[n-1];
        
        return ans;
    }
    
    string countAndSay(int n) {
        
        string temp= "1";
        if(n==1) return temp;
        
        for(int i=2;i<=n;i++){
            
            temp = solver(temp);
            // cout<<temp<<endl;
            
        }
        
        return temp;
        
    }
};