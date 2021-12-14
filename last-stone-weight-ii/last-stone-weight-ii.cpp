
int dp[35][3005];

class Solution {
public:    
        // a< b < c < d
        // 1 4 6 9
        // a c-b d
        // 1 6-4 9  -->1 2 9
        // a (d-(c-b))--> a, d, -c, b
        // 1 (9-(6-4))--> 1 ,7
        // (d-(c-b)) - a --> d, -c, b , -a 
        // (9-(6-4))-1 --> 6    
        // simlar of putting +/- infront of every number and take minimum subset sum
    
    //   1 2 3
    //   1 2 3
    
    int solver(int idx,vector<int>& st,int currsum,int ttlsum)
    {
        int n = st.size();
        if(idx>n)
            return INT_MAX;
        if(idx==n)
        {
            return abs(ttlsum-2*currsum);
        }
        
        if(dp[idx][currsum]!=-1)
        {
            return dp[idx][currsum];
        }
        
        int op1= solver(idx+1,st,currsum+st[idx],ttlsum);
        int op2= solver(idx+1,st,currsum,ttlsum);
        
        return dp[idx][currsum]=min(op1,op2);
    }
    
    int lastStoneWeightII(vector<int>& st) {
        
        int n = st.size();
        int sum = accumulate(st.begin(),st.end(),0);
                
           memset(dp,-1,sizeof dp);
        
//         for (int i = 0; i <= n; i++)
//           dp[i][0] = 1;
 
//       for (int i = 1; i <= sum; i++)
//             dp[0][i] = 0;
            
        
//         for (int i = 1; i <= n; i++) 
//         {
//         for (int j = 1; j <= sum; j++) 
//         {
//             // If i'th element is excluded
//             dp[i][j] = dp[i - 1][j];
 
//             // If i'th element is included
//             if (st[i - 1] <= j)
//                 dp[i][j] |= dp[i - 1][j - st[i - 1]];
//         }
//        }
        
//         int diff= INT_MAX;
        
//         for (int j = sum / 2; j >= 0; j--) 
//         {

//         if (dp[n][j] == 1) {
//             diff = sum - 2 * j;
//             break;
//         }
//         }
        
//         return diff;
            
          return solver(0,st,0,sum);  
    }
};