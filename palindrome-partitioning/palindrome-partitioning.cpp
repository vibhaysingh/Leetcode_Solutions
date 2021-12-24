class Solution {
public:
    vector<vector<string>>ans;
    
    bool isPalindrome(string s)
    {
        int n = s.size();
        
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
             return false;
        }
        return true;
        
    }
    
    void solver(int idx,string s,vector<string>&temp)
    {
        
        if(idx==s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        
        
        for(int i=idx;i<s.size();i++)
        {
            
            string x = s.substr(idx,i-idx+1);
            
            if(isPalindrome(x))
            {
                temp.push_back(x);
                solver(i+1,s,temp);
                temp.pop_back();
            }
            
            
        }
        
        
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        vector<string>temp;
        
        solver(0,s,temp);
        
        return ans;
        
    }
};