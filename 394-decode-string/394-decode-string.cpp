class Solution {
public:
    
    
    string solver(int &i,string&s){
       
        int n = s.size();
        
        string word="";
        int nums = 0;
        
        while(i < n){
            
            char curr = s[i];
            
            if(curr=='['){
                
                i++;
                string x = solver(i,s);
                
                while(nums--){
                    word+=x;
                }
                nums=0;
                                
            }
            else if('0'<=curr && curr<='9'){
                
                nums = nums*10 + (curr-'0');
            }
            else if('a'<=curr && curr<='z'){
                
                word+=curr;
            }
            else if(curr == ']'){
                
                return word;
            }
            
           i++; 
        }
        
        return word;
    }
    
    string decodeString(string s) {
        
        int i=0;
        
        return solver(i,s);
        
    }
};