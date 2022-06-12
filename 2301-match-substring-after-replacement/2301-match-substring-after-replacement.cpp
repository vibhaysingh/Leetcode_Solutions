class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mps) {
        
        
        int n = s.size();
        int z = sub.size();
        
        unordered_map<char,unordered_set<char>>mp;
        
        for(auto k:mps){
            
            mp[k[0]].insert(k[1]);
        }
        
       
        
        for(int i=0;i<n;i++)  {
            
            
                
                int j=0;
                int l = i;
                
                
                
        while(j<sub.size() && l<s.size() && ( s[l]==sub[j]  ||  (  mp.find(sub[j])!=mp.end()  && mp[sub[j]].find(s[l]) !=mp[sub[j]].end()) ))             {                  
            
                    l++;
                    j++;
            
                
                }
            
          
                

                      
                if(j==sub.size()) return true;
            
          
                
            }
        
            return false;
        
        }
    
                
                    
            
        

};