class Solution {
public:
    map<int,string>mp;
    
    vector<string> solver(int idx,string digits){
        
        if(idx>=digits.size()) { 
            vector<string>temp; 
            temp.push_back("");
            return temp;
        };
        
        vector<string>rd = solver(idx+1,digits);
        
        string curr = mp[digits[idx]];
        
        vector<string>ans;
        
        for(auto k:curr){
            
            string x="";
            x+=k;
            
            
            for(int i=0;i<rd.size();i++){
                
                x+=rd[i];
                
                ans.push_back(x);
                x=k;
            }
        }
        
        return ans;
        
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0) return {};
        
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
       
        return solver(0,digits);
        
    }
};