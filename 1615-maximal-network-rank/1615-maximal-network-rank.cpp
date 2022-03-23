class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int>cnt(n,0);
         set<pair<int,int>>mp;
        for(auto k:roads){
            
            cnt[k[0]]+=1;
            cnt[k[1]]+=1;
            int x=k[0],y=k[1];
                            if(x>y)swap(x,y);
            mp.insert({x,y});
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                if(i==j)continue;
                
                
                int x=i,y=j;
                if(x>y)swap(x,y);
                
                if(mp.find(make_pair(x,y))!=mp.end()){
                    
                    ans=max(ans,cnt[i]+cnt[j]-1);
                }
                else{
                     ans=max(ans,cnt[i]+cnt[j]);
                }
            }
        }
        
        return ans;
    }
};