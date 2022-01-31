class Solution {
public:
    
    int check(map<char,int>&mp){
        
        char key;
        int mx = 0;
        
        for(auto k:mp){
            
            if(k.second>mx){
                
                mx = k.second;
                key = k.first;
            }
        }
        
        int cnt=0;
        for(auto k:mp){
            
            if(k.first!=key){
                
                cnt+=k.second;
            }
        }
        
        
        return cnt;
    }
    
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        
        int start =0 , end = 0 , ans=0;
        
        
        map<char,int>mp;
        
        while(end<n){
            
            mp[s[end]]++;
            
            while(check(mp)>k){
                
                mp[s[start]]--;
                
                if(mp[s[start]]==0) mp.erase(s[start]);
                
                start++;
                
                
            }
            
            ans = max(ans,end-start+1);
            
            end++;
            
        }
        
        return ans;
        
    }
};