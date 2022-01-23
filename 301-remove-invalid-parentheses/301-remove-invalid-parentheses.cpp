class Solution {
public:
    
    
    unordered_set<string>st;
    
    bool isvalid(vector<char>&temp){
        
        int c=0;
        
        for(int i=0;i<temp.size();i++){
            
            if(temp[i]=='('){
                c++;
            }
            else if (temp[i]==')'){
                c--;
            }
            
            if(c<0) return false;
        }
        
        return (c==0);
    }
    
    void solver(int idx,string &s, vector<char>&temp,int &mx){
        
        
        if(idx>=s.size()){
            
            if(isvalid(temp)&&temp.size()==mx){
                
                string x(temp.begin(),temp.end());
                st.insert(x);
                
                return;
            }
            
            return;
        }
        
        // include this index
        temp.push_back(s[idx]);
        solver(idx+1,s,temp,mx);
         
        // exclude this index
         temp.pop_back();
        if(s[idx]=='('||s[idx]==')'){
        
        
         solver(idx+1,s,temp,mx);
            
        }
        
        return;
        
        
    }
    
    vector<string> removeInvalidParentheses(string s) {
        
        vector<char>temp;
        
        
        
        
        int c =0;
        int mx = 0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='('){
                c++;
            }
            else if(s[i]==')')
            {
                if(c){
                    mx+=2;
                    c--;
                }
            }
            else
            {
                mx++;
            }
        }
        
        solver(0,s,temp,mx);
        
        vector<string>ans;
        
        
        // unordered_set<string>st;
        
        for(auto k:st){
            
           ans.push_back(k);
        }
        
        return ans;
        
    }
};