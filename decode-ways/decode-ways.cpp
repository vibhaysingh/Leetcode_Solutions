
int dp[105];

class Solution {
public:
    
    bool valid(string a)
    {
             
        if(a=="")
            return false;
        if(a=="0")
            return false;
        
        int x =stoi(a);
            if(x>26) return false;
        return true;
    }
    
    int solver(int idx,string s)
    {
        
        int n = s.size();
        
        
             
        string a="",b="";
         a = s[idx];
        if(idx+1<n)
         b = a+s[idx+1];
        
        // cout<<a<<" "<<b<<endl;
        
        if(idx>n)
            return 0;
        // cout<<"idx"<<" "<<idx<<endl;
        // if(!valid(a))
        //     return 0;
        
        if(idx==n)
         return 1;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
         int x1=0,x2=0;
         if(valid(a)){
         x1 += solver(idx+1,s);
         if(valid(b))
         x2 += solver(idx+2,s);
         }
        
        return dp[idx]=x1+x2;
        
    }
    
    
    int numDecodings(string s) {
        
        memset(dp,-1,sizeof dp);
        
        return solver(0,s);
    }
};

// "27"
// "111111111111111111111111111111111111111111111"
// "10"
// "2611055971756562"