class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        int req;
        
        vector<int>x(4);
        
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
                        
            x[0]=nums[i];
            
            for(int j=i+1;j<n;j++){
                
                req = target - (nums[i]+nums[j]);
                
                x[1]=nums[j];
                
                
                int l = j+1,r=n-1;
                
                while(l<r){
                    
                    if(nums[l]+nums[r]>req){
                        r--;
                    }
                    else if(nums[l]+nums[r]<req){
                        l++;
                    }
                    
                    else{
                        
                        
                        
                        x[0]=nums[i];
                        x[1]=nums[j];
                        x[2]=nums[l];
                        x[3]=nums[r];
                        
                        ans.push_back(x);
                        
                        
                        while(l<r && x[2]==nums[l]) l++;
                        
                        
                        while(l<r && x[3]==nums[r]) r--;
                        
                    }
                }
                
                 while(j+1<n && x[1]==nums[j+1]) j++;
            }
            
           
                        
            
             while(i+1<n && x[0]==nums[i+1]) i++;
        }
        
       return ans;
        
    }
};