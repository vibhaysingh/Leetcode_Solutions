class Solution {
public:
    
    vector<string>ans;
    
    void solver(int open,int close , string &s){
        
        
        // cout<<open<<close<<endl;
        if(open==0 && close==0){
            // cout<<"loop"<<endl;
            ans.push_back(s);
            return;
        }
        if(open<0||close<0) return;
        
        if(open){
            s+='(';
            solver(open-1,close,s);
            s.pop_back();
        }
        if(open<close)
        {
            s+=')';
            solver(open,close-1,s);
            s.pop_back();
        }
        
   
    }
    
    vector<string> generateParenthesis(int n) {
        
        int open=n;
        int close=n;
        string s="";
        
        solver(open,close,s);
        return ans;
    }
};