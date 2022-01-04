class Solution {
public:
    
    int ans = 0;
    vector<int>temp;
    
    void mergeSort(int l, int r,vector<int>& nums){
        
        if(l>=r) return;
        
        int mid  = (l+r)/2;
        
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);
        
        int i=l,j=mid+1,k=l;
        
        for(i=l;i<=mid;i++){
            
            while(j<=r && nums[i] > 2LL*nums[j] ) 
                j++;
            
            ans+=(j-mid-1);
            
        }
        
        
        i=l,j=mid+1,k=l;
        
        // cout<<l<<r<<mid<<endl;
        
        while(i<=mid && j<=r){  
            
            if(nums[i] <=nums[j]){
                
                temp[k++]=nums[i++];
            }else{
                
            temp[k++]=nums[j++];
            }
        }
        
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        
         while(j<=r){
            temp[k++]=nums[j++];
        }
        
        for(int i=l;i<=r;i++){
            nums[i]=temp[i];
        }
        
        
        
    }
    
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        temp.resize(n);
        ans=0;
        mergeSort(0,n-1,nums);
        
        return ans;
        
        
    }
};