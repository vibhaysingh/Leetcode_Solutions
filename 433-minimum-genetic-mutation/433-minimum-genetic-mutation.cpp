class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string>st(bank.begin(),bank.end());
        
        int ans=0;
        
        queue<string>q;
        
        if(start==end) return 0;
        
        if(bank.size()==0) return -1;
        
        q.push(start);
        
        while(!q.empty()){
            
            int l = q.size();
            
            while(l--){
                
                auto x = q.front();
                q.pop();
                
                if(x==end) return ans;
                
                
                for(int i=0;i<x.size();i++){
                    
                    char c=x[i];
                    
                    for(char d:{'A','C','G','T'}){
                        
                        if(c==d){
                            continue;
                        }
                        
                        x[i]=d;
                        
                        if(st.find(x)!=st.end()){
                            
                            q.push(x);
                            st.erase(x);
                        }
                        
                        x[i]=c;
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
        
        
    }
};