class Solution {
public:
    
    
    bool possible(vector<int>& batteries,long long mid,int n){
        
        long long sum = 0;
        
        for(int i=0;i<batteries.size();i++){
            
            sum+=min((long long)batteries[i],mid);
        }
        
        
        return (sum>=(long long)n*mid);
        
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        
        
        long long low = 0,high=0,mid;
        
        for(auto k:batteries){
            high+=k;
        }
        
        long long ans = 0;
        
        while(low<=high){
            
            mid = (low+high)/2;
            
            if(possible(batteries,mid,n)){
                ans = max(ans,mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return ans;
        
    }
};