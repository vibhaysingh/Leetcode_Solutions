class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        
        string ans;
        
        string word;
        vector<string>v;
        while(ss>>word){
            v.push_back(word);
        }
        
        for(int i=v.size()-1;i>=0;i--){
            
            ans+=v[i];
            ans+=" ";
        }
        
        ans.pop_back();
        
        return ans;
        
        
        
        
    }
};