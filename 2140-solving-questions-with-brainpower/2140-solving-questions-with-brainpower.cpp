
long long  dp[100005];

class Solution {
public:
    
    long long ans = 0;
    
    long long solver(int idx , vector<vector<int>>& questions){
        
        int n = questions.size();
        
        if(idx>=n) return 0;
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        // take curr idx
        
        
        
        
        long long  temp1 = questions[idx][0]+solver(idx+questions[idx][1]+1,questions);
        
        // cout<<idx<<" "<<temp1<<endl;
        
        // ignore curr idx
        
        long long  temp2 = solver(idx+1,questions);
        
        return dp[idx]=max(temp1,temp2);
        
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
         memset(dp,-1,sizeof dp);
        return solver(0,questions);
    }
};