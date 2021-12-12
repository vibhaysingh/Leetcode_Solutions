
int dp[100000][30];
const int mod = 1e9+7;
class Solution {
public:
    
    bool isValid(char prev,char curr)
    {
        if(prev=='a'&&curr=='e')
            return true;
        else if(prev=='e'&&(curr=='a'||curr=='i'))
            return true;
        else if(prev=='i'&&curr!='i')
            return true;
        else if(prev=='o'&&(curr=='i'||curr=='u'))
            return true;
        else if(prev=='u'&&curr=='a')
            return true;
        
        return false;
        
    }
    
    int solver(int idx,int n, char prev)
    {
        if(idx>n)
            return 0;
        if(idx==n)
        {
            return 1;
        }
        
        if(dp[idx][prev-'a']!=-1)
        {
            return dp[idx][prev-'a'];
        }
        
        int temp=0;
        
        for(auto ch:{'a','e','i','o','u'})
        {
            if(isValid(prev,ch))
            {
                temp = (temp%mod+solver(idx+1,n,ch)%mod)%mod;
            }
        }
        
        return dp[idx][prev-'a']=temp;
    }
    
    
    int countVowelPermutation(int n) {
        
        
        memset(dp,-1,sizeof dp);
        
        int temp=0;
        
        for(auto ch:{'a','e','i','o','u'})
        {
           temp = (temp%mod+solver(1,n,ch)%mod)%mod;
            
        }
        
        return temp;
        
    }
};