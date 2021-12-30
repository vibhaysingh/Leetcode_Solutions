#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update > pbds;


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        pbds A;
        int n =nums.size();
        vector<int>ans(n);
        
        for(int i=n-1;i>=0;i--){
            
            int cnt = A.order_of_key({nums[i],INT_MIN});
            ans[i]=cnt;
            A.insert({nums[i],i});
            // cout<<A.size()<<endl;
            
        }
        return ans;
    }
};