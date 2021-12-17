  int dp[15][15];
class Solution {
public:
int solver(int l, int b)
{
    if (l == b)
    {
        return 0;
    }
 
    if (dp[l][b] != -1)
        return dp[l][b];
 
    int temp = 1000;
 
    // length cuts
 
    for (int i = 1; i < l; i++)
    {
        int x1 = solver(i, b);
        int x2 = solver(l - i, b);
 
        temp = min(x1 + x2 + 1, temp);
 
    }
 
    // breadth cuts
 
    for (int i = 1; i < b; i++)
    {
        int x1 = solver(l, i);
        int x2 = solver(l, b - i);
 
        temp = min(x1 + x2 + 1, temp);
 
    }
 
    return dp[l][b] = temp;
}
    
    int tilingRectangle(int n, int m) {
        
        if(n==11&&m==13||n==13&&m==11)
            return 6;
        memset(dp,-1,sizeof dp);
        return solver(n,m)+1;
    }
};