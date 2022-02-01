class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        
        int start=0; // assuming start to be 0
        int ttl =0;
        int temp = 0;
        
        int n = gas.size();
        
        for(int i=0;i<n;i++){
            
            ttl+=gas[i]-cost[i];
            temp+= gas[i]-cost[i];
            
            if(temp<0){
                
                start=i+1;
                temp=0;
            }
        }
        
        return ttl>=0 ? start :-1;
        
        
    }
};