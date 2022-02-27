class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int ct, int nl) {
        
        
        vector<long long >dp1(16,INT_MAX);
        vector<long long >dp2(nl+1,INT_MAX);
        
        int n = tires.size();
        
        for(int i=0;i<n;i++){
            
            long long  int fi = tires[i][0];
            long long  int ri = tires[i][1];
            long long  int ttl = tires[i][0];
            long long int t = fi;
            
            dp1[1] = min(dp1[1],fi);
            
            for(int j=2;j<16;j++){
                
               t*= ri;
                
                ttl+=t;
                
                if(ttl>INT_MAX) break;
                
                dp1[j] = min(dp1[j],ttl);
            }
        }
        
        
        for(int i=1;i<=nl;i++){
            
            if(i<16){
                dp2[i] = dp1[i];
            }
            
            for(int j=i-1;j>=max(i-15,1);j--)
            {
                
                dp2[i] = min(dp2[i],dp2[j]+ct+dp2[i-j]);
            }
        }
        
        return dp2[nl];
        
    }
};