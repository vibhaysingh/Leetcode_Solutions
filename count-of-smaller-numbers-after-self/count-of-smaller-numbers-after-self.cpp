class Solution {
public:
    
    vector<pair<int,int>>temp; 
    void merge_sort(int s,int e, vector<pair<int,int>>&vp,vector<int>&ans){
        
        if(s>=e) return;
        
        int mid = s + (e-s)/2;
        
        // cout<<s<<" "<<e<<" "<<mid<<endl;
        
        merge_sort(s,mid,vp,ans); // sort left subarray
        merge_sort(mid+1,e,vp,ans); // sort right subarray
        
        // now left portion is sorted ans right portion is aloso sorted 
        // now its time to merge
        
        int l=s; // l points to 1st element in left subarray
        int r=mid+1; // r points to 1st element in right subarray
        int idx=s;// idx points to 1st element in merged temp array
        
        int count=0;
        // cout<<s<<" "<<e<<" "<<mid<<" merge hone"<<endl;
        
        while(l<=mid && r<=e)
          {
            
            if(vp[l].first <= vp[r].first){ 
                
                ans[vp[l].second]+=count;
                temp[idx++]=vp[l++];
            }
            else
            { 
                // cout<<"xyz"<<idx<<endl;
                temp[idx++] = vp[r++];    
                count++;
                            
            }
            
        }
        
        // cout<<r<<" r "<<idx<<" idx"<<endl;
        
        
        while(l<=mid){
            
            ans[vp[l].second]+=count;
            temp[idx++]=vp[l++];
        }
        
        
         while(r<=e){
             
             temp[idx++]=vp[r++];
         }
        
        for(int i=s;i<=e;i++){
            vp[i]=temp[i];
            // cout<<vp[i].first<<" here"<<endl;
        }
        
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>>vp(n);
        vector<int>ans(n,0);
        temp.resize(n);
        
        for(int i=0;i<n;i++){
            vp[i]=make_pair(nums[i],i);
            
        }
        
        merge_sort(0,n-1,vp,ans);
        
        return ans;
        
        
    }
};