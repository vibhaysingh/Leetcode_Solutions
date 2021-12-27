int dp[2005][2005];

class Solution {
public:
    unordered_map<int,int>mp;
    vector<int>v;
    
   bool solver(int pos,int target,int k){  
       
       if(pos<0||pos>target) return false;
       
        if(pos==target) return true;
       
      if(dp[pos][k]!=-1)
          return dp[pos][k];
       
       // cout<<pos<<endl;
       
       int x1 = v[pos]+(k-1); // 1+0 1 ye values hai
       int x2 = v[pos]+(k);  // 1+1  2
       int x3 = v[pos]+(k+1); // 1+2 3
       
       
       
       bool f= false;
       
       if(mp.count(x1) && mp[x1]>pos&&!f)
       {
          f=f|solver(mp[x1],target,k-1);
       }
       
       if( mp.count(x2)&&mp[x2]>pos&&!f)
       {
          f=f|solver(mp[x2],target,k);
       }
       
       if(mp.count(x3)&&mp[x3]>pos &&!f)
       {
          f=f|solver(mp[x3],target,k+1);
       } 
       
       return dp[pos][k]=f;
       
   } 
    
    bool canCross(vector<int>& stones) {
        
        if(stones[1]!=1)return false;        
        for(int i=0;i<stones.size();i++){
           mp[stones[i]]=i;
        }
        v=stones;
        memset(dp,-1,sizeof dp);
        return solver(1,stones.size()-1,1);
        
    }
};