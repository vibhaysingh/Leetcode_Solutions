class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        
        vector<pair<int,int>>vp;
        
        for(auto k:b){
            vp.push_back({k[0],-k[2]}); // start height
            vp.push_back({k[1],k[2]}); // end  height
        }
        
        sort(vp.begin(),vp.end());
        
        // for(auto k:vp)cout<<k.first<<" "<<k.second<<endl;
        
        multiset<int>st;
        vector<vector<int>>ans;
        st.insert(0);
        
        int cht=0;
        
        for(int i=0;i<vp.size();i++){
            
            int x = vp[i].first;
            int ht = vp[i].second;
            
            if(ht<0){
                st.insert(-ht);
            }
            else{
                st.erase(st.find(ht));
            }
            
            int mxh = *prev(st.end());
            
            if(cht!=mxh){
                cout<<i<<endl;
                ans.push_back({x,mxh});
                cht=mxh;
            }
        }
        
        return ans;
        
    }
};