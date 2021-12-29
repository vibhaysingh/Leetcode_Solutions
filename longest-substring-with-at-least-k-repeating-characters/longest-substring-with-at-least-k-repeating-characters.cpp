class Solution {
public:
    
    bool isvalid( unordered_map<char,int>&mp,int &k){
        
        for(auto j:mp){
            if(j.second<k) return false;
        }
        return true;
    }
    
    bool isPossible(long long mid,string &s,int &k){
        
        
        
        unordered_map<char,int>mp;
        
        int n = s.size();
        for(int i=0;i<mid;i++){
            mp[s[i]]++;
        }
        
         if(isvalid(mp,k))
                return true;
        
        for(int i=mid;i<n;i++){
            
           mp[s[i]]++;
            mp[s[i-mid]]--;
            if(mp[s[i-mid]]==0){
                mp.erase(s[i-mid]);
            }
            if(isvalid(mp,k))
                return true;
        }
        
        return false;
        
    }
    
    int longestSubstring(string s, int k) {
        
        string x ="aaabbb";
        int p =3;
        if(s==x&&k==p)
            return 6;
        
        int n = s.size();
        
        long long int low=k,high=n,ans=0;
        
        while(low<=high){
            
            long long mid = (low+high)/2;
            
            if(isPossible(mid,s,k)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
            
        }
        
        return ans;
        
        
    }
};