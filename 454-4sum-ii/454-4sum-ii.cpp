class Solution {
public:
    int fourSumCount(vector<int>& num1, vector<int>& num2, vector<int>& num3, vector<int>& num4) {
        
        map<int,int>mp;
        
        int n = num1.size();
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                mp[num1[i]+num2[j]]++;
            }
        }
        
        
        
         for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
               if(mp.find(-num3[i]-num4[j])!=mp.end()){
                   
                   cnt+=mp[-num3[i]-num4[j]];
               }
            }
         }
                           return cnt;
        
    }
};