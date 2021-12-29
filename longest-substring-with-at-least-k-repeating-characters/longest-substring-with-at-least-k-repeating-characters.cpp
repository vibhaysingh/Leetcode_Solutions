class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = s.size();
        
        int mp[26];
        int ans=0;
        for(int i=1;i<=26;i++){ // type of characters
            
            // count longest substring having only i unique character and 
            // frequency of every character if greater than equal to k
            
            memset(mp,0,sizeof mp);
            
            int left=0,right=0,unique=0,minkcount=0;
            
            while(right<n){
                
                // unique [req unique] se kam hai mai right ko extend krunga
                if(unique <= i){
                    
                    int idx = s[right]-'a';
                    if(mp[idx]==0) unique++;
                    mp[idx]++;
                    if(mp[idx]==k)
                        minkcount++;
                    // cout<<right<<" right"<<endl;
                    right++;
                        
                }else {
                    
                     // cout<<left<<" left"<<endl;
                    int idx = s[left] - 'a';
                    
                    if(mp[idx]==k)
                        minkcount--;
                    mp[idx]--;
                    if(mp[idx]==0)
                        unique--;
                    left++;
                    
                }
                
                 if(unique==i&&unique==minkcount)
                ans=max(ans,right-left);
            }
            
           
            
        }
        return ans;
        
        
    }
};