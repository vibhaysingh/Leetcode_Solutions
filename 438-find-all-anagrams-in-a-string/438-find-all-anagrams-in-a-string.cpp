class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        
        vector<int>v(26,0);
        
        for(int i=0;i<p.size();i++){
            
            v[p[i]-'a']++;
        }
        
        int i=0,j=0;
        
        vector<int>ans;
        
        while(i<s.size()){
            
            v[s[i]-'a']--;
            
            // cout<<v[s[i]-'a']<<endl;
         
            while(v[s[i]-'a']<0){
                
                v[s[j]-'a']++;
              
                
                if(i-j==p.size()){
                    ans.push_back(j);
                }
                
                j++;
                
            }
            
             // if(i-j==p.size()){
             //        ans.push_back(j);
             //    }
            i++;
        }
         if(i-j==p.size()){
                    ans.push_back(j);
            }
      
        return ans;
    }
};

// abab
