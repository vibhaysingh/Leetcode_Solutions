class Solution {
public:
    
    
    
    int evalRPN(vector<string>& nums) {
        
        
        stack<int>st;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            if(nums[i]=="+"||nums[i]=="-"||nums[i]=="*"||nums[i]=="/"){
                
                
               
                
                int num2 = st.top();
                
                // cout<<i<<endl;
                
                st.pop();
                
                 int num1 = st.top();
                st.pop();
                
                // cout<<
                
                if(nums[i]=="+"){
                    st.push(num1+num2);
                }
                  if(nums[i]=="-"){
                    st.push(num1-num2);
                }
                  if(nums[i]=="*"){
                    st.push(num1*num2);
                }
                  if(nums[i]=="/"){
                    st.push(num1/num2);
                }
                
                // i++;
            }
            else{
                st.push(stoi(nums[i]));
            }
        }
        
        return st.top();
    }
};