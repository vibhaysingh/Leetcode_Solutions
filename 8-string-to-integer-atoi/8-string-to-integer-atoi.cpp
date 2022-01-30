class Solution {
public:
    int myAtoi(string s) {
        
        long long ans=0;
        
        int m = INT_MAX;
        int sign = 1;
        bool f= false;
        int n = s.size();
       
        for(int i=0;i<s.size();i++){
            
            if(s[i]==' ') continue;
            
            if(isdigit(s[i])){
                
                
                
                ans = (ans*10 + s[i]-'0');
                
                if(ans>INT_MAX && sign==1){
                    ans = INT_MAX;
                    break;
                }
                else if(sign==-1 && (ans*sign)<INT_MIN){
                    
                    // cout<<i<<" "<<ans<<endl;
                    ans = INT_MIN;
                    
                    break;
                }
                
                if(i+1<n && !isdigit(s[i+1])) break;
                
            }
            else if(s[i]=='-'){
                sign=-1;
                
                if(i+1<n && !isdigit(s[i+1])) break;
                 else if(i==n-1)break;
                else if(i>0 && s[i-1]!=' ')break;
            }
            else if(s[i]=='+'){
                sign=1;
                if(i+1<n && !isdigit(s[i+1])) break;
                else if(i==n-1)break;
                else if(i>0 && s[i-1]!=' ')break;
                
            }
            else{
                break;
            }
            
            
        }
        
        return sign*ans;
        
    }
};