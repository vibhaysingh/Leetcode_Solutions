class Solution {
public:
    
    bool valid(unordered_map<char,int>&mp){
        
        for(auto k:mp){
            
            if(k.second>1)
                return false;
        }
        return true;
    }
    
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        unordered_map<char,int>mp;
        
        int i=0, j=0;
        int ans=0;
        
//         while(j<n){
            
//             mp[s[j]]++;
            
//             while(!valid(mp)){
                
//                 mp[s[i]]--;
//                 if(mp[s[i]]==0){
//                     mp.erase(s[i]);
//                 }
//                 i++;
//             }
            
//             ans = max(ans,j-i+1);
//             j++;
            
//         }
        
        
        while(i<n && j<n){
            
            
            if(mp.count(s[i])==0){
                mp[s[i]]=i;
                ans = max(ans,i-j+1);
            }else{
                
                int prevIdx = mp[s[i]];
                j = max(j,prevIdx+1);
               ans = max(ans,i-j+1);
                mp[s[i]]=i;
            }
            i++;
        }
        
        return ans;
        
        
        
    }
};