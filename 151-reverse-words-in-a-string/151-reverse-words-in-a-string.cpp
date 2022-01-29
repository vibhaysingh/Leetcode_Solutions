class Solution {
public:
    string reverseWords(string s) {
        
        
        int n = s.size();
        
        // reverse whole string
        
        reverse(0,n-1,s);
        
        // reverse each words 
        
        reverseWord(s,n);
        
        /// remove extra spaces
        
        removeSpaces(s,n);
        
        return s;
        
    }
    
    
    void reverse(int i,int j,string &s){
        
        while(i<j){
            
            swap(s[i++],s[j--]);
        }
    }
    
    void reverseWord(string &s, int n){
        
        int i=0;
        int j=0;
        
        while(i<n){
            
            i=j;
            
            while(i<n && s[i]==' ') i++; // skip spaces
            
            // now i points to a character
            
            j=i;
            
            // increase j untill the next space is found;
            
            while(j<n && s[j]!=' ')j++;
            
            // j points to space of end of string 
            
            reverse(i,j-1,s);            
        }
        
       
    }
    
    void removeSpaces(string &s, int n){
        
        int i=0;
        int j=0;
        
        while(j<n){
            
            // skip spaces
            
            while(j<n && s[j]==' ')j++;
            
            // j points to character
            
            while(j<n && s[j]!=' '){
                swap(s[i++],s[j++]);
            }
            
            // j points to space
            
            // add one space before prev word
            
            if(j<n){
                swap(s[i++],s[j++]);
            }
            
        }
        
         // pop all spaces from back of string
        
        while(s.back()==' ') s.pop_back();
        
    }
    
};