class Solution {
private:
    string s;
    int rec(int &i){
        int c=0,ans=0;
        while(i<s.size()){
            
            if(s[i]=='('){
                
                if(s[i+1]==')'){
                    ans+=1;
                    i+=2;
                    if(i<s.size() && s[i]=='('){
                        return ans+rec(i);
                    }
                    else
                    return 1;
                }
                
                i++;
                ans+=(2*rec(i));
            }
            else{
                
                if(i+1<s.size() && s[i+1]=='('){
                    i++;
                    return ans+rec(i);
                }
                i++;
                return ans;
            }
        }
        return ans;
    }
    
    // (())()
public:
    int scoreOfParentheses(string s) {
        this->s=s;
        int i=0;
        return rec(i);
    }
};