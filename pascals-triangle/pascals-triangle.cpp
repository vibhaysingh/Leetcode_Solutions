class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(1);
        ans.push_back(temp);
        int count=1;
        while(count<numRows){
            
            temp.clear();
            temp.push_back(1);
            for(int i=1;i<ans[count-1].size();i++){
                
                temp.push_back(ans[count-1][i-1]+ans[count-1][i]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            count++;
            
        }
        
        return ans;
        
    }
};