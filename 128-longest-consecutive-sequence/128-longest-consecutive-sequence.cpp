class Solution {
public:
    
    int findPar(int x, unordered_map<int,int>&par){
        
        if(x==par[x])
            return par[x];
        return par[x]= findPar(par[x],par);
        
    }
    
    void unionn(int a, int b,unordered_map<int,int>&par){
        
        int pb= findPar(b,par);
        int pa= findPar(a,par);
        
        
            par[pb]=pa;
        
        
    }
    
    
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int>par; //<x,parent of x>
        unordered_map<int,int>count; //<x,size of x as a root>
        
        for(int i=0;i<n;i++){ // sare nums  khud ke hi parent hai
           
            par[nums[i]]=nums[i];
            
        }
        
        for(int i=0;i<n;i++){            
            if(par.find(nums[i]-1)!= par.end()){
                // cout<<nums[i]-1<<endl;
                unionn(nums[i],nums[i]-1,par);
            }
        }
            
          
            for(auto k:par){                
                count[findPar(k.first,par)]++;
            }
            
            int ans = 0;
        
            for(auto k:count){
                ans = max(ans,k.second);
            }
            
            
        
        return ans;
    }
};