class Solution {
public:
    
   
    int nthUglyNumber(int n) {    
//         set<unsigned long long int>st1;
//         set<unsigned long long int>st2;        
//         st1.insert(1);
//         st2.insert(1);       
//         while(st2.size()<=1690)
//         {
//             unsigned long long int x = *st1.begin();
//             st1.erase(st1.begin());           
//             for(unsigned long long int i:{2,3,5})
//             {
//                 if(i*x<=INT_MAX)
//                 {
//                   st1.insert(i*x);
//                   st2.insert(i*x);
//                 }
//             }            
//         }       
//         int count=1;
//         int ans;
//         while(count<n)
//         {
//             // cout<<pq.top()<<" "<<count<<endl;
//             st2.erase(st2.begin());
//             count++;
//         }
        
//         return (int)*st2.begin();
        
        vector<int>dp(n,0);
        int p2=0,p3=0,p5=0; // pointers for 2,3,5
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            int x = min({2*dp[p2],3*dp[p3],5*dp[p5]});
            dp[i]=x;
            if(x==2*dp[p2])p2++;
            if(x==3*dp[p3])p3++;
            if(x==5*dp[p5])p5++;
        }
        
        return dp[n-1];
    }
};