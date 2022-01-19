class Solution {
public:
    
    bool isvalid(string s){
        
        if(s.size()>3)return false;
        
        if(s.size()==0) return false;
        
        if(s.size()==1&&s[0]=='0') return true;
        
        if(s[0]=='0') return false;
        
        int x = stoi(s);
        
        if(x>255) return false;
        
        return true;
        
        
    }
    vector<string>ans;
    void solver(int idx,string &s,string &temp,int cnt){
        
        if(idx == s.size()&&cnt==0){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            
            string x = s.substr(idx,i-idx+1);
            
            if(isvalid(x)&&cnt){
                
                // cout<<x<<endl;
                string y = temp;
                x+='.'; 
                
                temp+=x;
                                
                solver(i+1,s,temp,cnt-1);                
                temp=y;  
                
            }
            
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        ans.clear();
        
        string temp = "";
        
        solver(0,s,temp,4);
        
        return ans;
    }
};