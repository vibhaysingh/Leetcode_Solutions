

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {       
        int l = primes.size();
        vector<int>dp(n,0);// storing ith ugly number
//         vector<int>p(l,0); // each block is responsible for pointing each no in primes array
        
        dp[0]=1;
        
//         for(int i=1;i<n;i++)
//         {
            
//             int x=INT_MAX;
            
//             for(int j=0;j<l;j++)
//             {
//                 int pos=p[j];
//                 int val = primes[j];
                
//                 x= min(x,dp[pos]*val);
//             }
            
//             dp[i]=x;
            
//             for(int j=0;j<l;j++)
//             {
//                 int pos=p[j];
//                 int val = primes[j];
                
//                 if(dp[pos]*val==x)
//                 {
//                     p[j]++;
//                 }
//             }
            
            
//         }
        
//         return dp[n-1];
        
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       
        for(int i=0;i<l;i++){
        pq.push({primes[i],{0,i}});
       
        }
        
        for(int i=1;i<n;i++)
        {
            
            auto x = pq.top();
            pq.pop();
            
            dp[i]=x.first;
            // while(!pq.empty()&&dp[i]==pq.top().first)
            //     pq.pop();
            x.second.first++;
            x.first=(long long)dp[x.second.first]*(long long )primes[x.second.second];
            
            pq.push(x);
            
            if(dp[i-1]==dp[i])
                i--;
            
        }
        
//         for(auto k:dp)
//         {
//             cout<<k<<" ";
//         }
        
        return dp[n-1];
        
        
    }
};