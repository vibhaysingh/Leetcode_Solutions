class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int i = 0;
        int j = m-1;
        
        while(i>=0 && j>=0&&i<n&&j<m){
            
            if(mat[i][j]==target){
                return true;
            }else if(mat[i][j]>target){
                j--;
                
            }else{
                i++;                
            }
        }
        
        return false;
        
        
        
    }
};