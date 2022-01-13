class Solution {
public:
    
    vector<vector<string>>ans;
    
    bool ispalindrome(string x){
        
        string y=x;
        
        reverse(y.begin(),y.end());
        
        return (y==x);
    }
    
    void solver(int idx, string &s,vector<string>&temp){
        
        if(idx>=s.size()){
            ans.push_back(temp);
            return;
        }
        
        // cout<<idx<<endl;
         // i = 0 se n-1
        for(int i=idx;i<s.size();i++){
            
            string x = s.substr(idx, i-idx+1);
                        
            if(ispalindrome(x)){
                
                // cout<<i<<endl;
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