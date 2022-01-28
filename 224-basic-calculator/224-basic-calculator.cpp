class Solution {
public:
    
    int solver(int &i ,  string s){
        
        int ans = 0;
        int n = s.size();
        int num=0;
        int sign = 1; // 1 denotes positive
        while(i<n){            
            if(s[i]=='('){                
                i++;
                int x = solver(i,s);                
                ans+=sign*x;
                x=0;
                // return ans;
                
            }
            else if(isdigit(s[i])){
                                
                    num = num*10 + (s[i]-'0');
                    i++;             
            }
            else if(s[i]=='+'||s[i]=='-'){
                
                if(s[i]=='+'){
                    
                    
                    ans+=sign*num;
                    num=0;
                    sign=1;
                   
                    i++;
                                        
                }
                else if (s[i]=='-'){
                    
                    ans+=sign*num;
                    num=0;
                    sign=-1;
                    i++;
                    
                }
                
                
            }
            else if(s[i]==')'){
                
                ans+=sign*num;
                num=0;
          
                i++;
                return ans;
            }
            else if(s[i]==' '){
               
                i++;
            }
            
            
        }
        
         ans+=sign*num; 
        
        return ans;
        
    }
    
    int calculate(string s) {
        
        int n  = s.size();        
        int i=0;        
        return solver(i,s);
        
       
        
    }
};