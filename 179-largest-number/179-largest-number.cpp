bool comp(int &A,int &B){
    
    /// return true if first argument is placed before second
    
    string a = to_string(A);
    string b = to_string(B);
    
    string c = a+b;
    string d = b+a;
    
    if(c>d) return true;
    
    return false;
    
}

// [10,2]
// [3,30,34,5,9]
// [8308,8308,830]
// [10,2,9,39,17]

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end(),comp);
        
        // for(auto k:nums)cout<<k<<" ";cout<<endl;
        
        string ans="";
        
        bool allzero=true;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]!=0&&allzero) allzero=false;
            ans+=to_string(nums[i]);
        }
        
        if(allzero) return "0";
        return ans;
        
        
    }
};