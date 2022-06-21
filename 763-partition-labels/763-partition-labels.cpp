class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int>v(26,-1);
        
        int n = s.size();
        
        for(int i=n-1;i>=0;i--){
            
            if(v[s[i]-'a']==-1){
                v[s[i]-'a']=i;
            }
        }
        
        vector<int>ans;
        
        int mx=-1;
        int prev = 0;
        
        // bacba
        
        for(int i=0;i<n;i++){
            
              mx=max(mx,v[s[i]-'a']);
            if(i==mx){
              
                ans.push_back(i-prev+1);
                prev=i+1;
                mx=-1;
                
            }
        
            
            // cout<<mx<<endl;
           
        }
        
        return ans;
    }
};