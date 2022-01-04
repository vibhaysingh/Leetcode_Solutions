class Solution {
public:
    
    double solver(double x , int n){
        
        if(n==0){
            return (double)1;
        }
        
        double x1 = solver(x,n/2);
        
        if(n%2==0){
            return x1*x1;
        }
      
        return x1*x1*x;
    }
    
    double myPow(double x, int n) {
        
        double ans = solver(x,n);
        if(n<0)
            return 1/ans;
        return ans;
    }
};