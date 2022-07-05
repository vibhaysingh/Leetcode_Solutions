class Solution {
public:
    bool checkValidString(string s) {
        
        
        int n = s.size();
        
        int leftmin=0;
        int leftmax=0;
        
        for(auto k:s){
            
            if(k=='('){
                leftmin++;
                leftmax++;
            }
            else if(k==')'){
                
                leftmin--;
                leftmax--;
            }
            else{
                
                leftmax++;
                leftmin--;
            }
            
            if(leftmin<0)leftmin=0;
            if(leftmax<0) return false;
        }
        
        if(0>=leftmin && 0<=leftmax) return true;
        
        return false;
        
    }
};