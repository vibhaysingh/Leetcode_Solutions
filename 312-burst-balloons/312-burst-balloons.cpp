
int dp[502][502];
class Solution {
public:
    
  int solver(int i,int j,vector<int>&v){
        
        if(i>j) return 0;
     
     if(dp[i][j]!=-1) return dp[i][j];
        
       int temp = INT_MIN;
        
        for(int k=i;k<=j;k++){
            
            int x = (v[i-1]*v[k]*v[j+1]) + solver(i,k-1,v) + solver(k+1,j,v);
            
            temp = max(temp,x);
        }
        
        return dp[i][j]=temp;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        memset(dp,-1,sizeof dp);
        
        return solver(1,n,nums);
        
    }
};