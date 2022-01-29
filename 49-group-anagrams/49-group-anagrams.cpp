class Solution {
public:
    
    vector<int> hashString(string &s){
        
        vector<int>v(26,0);
        
        for(int i=0;i<s.size();i++){
            
            v[s[i]-'a']++;
        }
        
        return v;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>,vector<string> > mp;
        
        for(auto k:strs){
            
            vector<int> v = hashString(k);
                mp[v].push_back(k);
        }
        
        vector<vector<string>> ans;
        
        for(auto k:mp){
            ans.push_back(k.second);
        }
        
        return ans;
        
    }
};