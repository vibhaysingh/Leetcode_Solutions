class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        
        int n = mat.size();
       
        // transpose of matrix
        
        for(int dig=0;dig<n;dig++){
            
            for(int j= dig;j<n;j++){
                
                swap(mat[dig][j],mat[j][dig]);
            }
        }
        
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        
        
    }
};