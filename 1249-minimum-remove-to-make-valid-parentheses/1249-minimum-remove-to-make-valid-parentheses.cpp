class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
       stack<int>st;
        
       int n = s.size();
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='(')st.push(i);
            else if(s[i]==')' && !st.empty() && s[st.top()]=='('){
                st.pop();
                // cout<<i<<endl;
            }
            else if(s[i]==')'){
                st.push(i);
            }
        }
        
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        
        reverse(v.begin(),v.end());
        
        // for(auto k:v)cout<<k<<" ";
        // cout<<endl;
        
        string ans;
        
        int j=0;
        
        for(int i=0;i<n;i++){
            
            if( j<v.size() && i==v[j]){
                j++;
                continue;
            }
            
            ans+=s[i];
        }
        
        return ans;
        
        
        
    }
};