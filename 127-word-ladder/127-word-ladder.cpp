class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        
        set<string>st(wl.begin(),wl.end());
        
        
        queue<string>q;
        
        if(bw==ew||st.count(ew)==0)return 0;
        q.push(bw);
        int cnt=1;
        
        while(!q.empty()){
            
            
            int n = q.size();
           
            
            
            // cout<<x<<endl;
            
          
            
            while(n--)
            {
                string x = q.front();
            q.pop();
                
                  if(x == ew){
             
                 return cnt;
            }
                
                
            for(int i=0;i<x.size();i++){
                
                
                
                
                for(char c='a';c<='z';c++){
                    
                    char p = x[i];
                    
                    if(x[i]==c) continue;
                    
                    x[i]=c;
                    
                   
                    
                    if(st.count(x)>0){                        
                        q.push(x);                        
                        st.erase(x);
                    }
                    x[i]=p;
                    
                }
            }
        }  
            
            
                    
            cnt++;
            
            
        }
        
      return 0;  
    }
};