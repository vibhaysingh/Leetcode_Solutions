class Solution {
public:
    string removeKdigits(string s, int k) {
        
        int n  = s.size();
        
        int i=0, j=0,c=0;
        
        for(i=0;i<n;i++){
            
            if(s[i]=='0'){
                k-=c;
                c=0;
                j=i+1;
            }
            else{
                c++;
                if(c>k) break;
            }
        }
        
       int d = n-j-k;    //  req ans digits // 21-9 =12 - 3 = 9
           
           if(d<=0) return "0";
        
        deque<int>dq;
        string ans ="";
        for(i=j;i<n;){
            d--; // filling xth digit of ans from left to right digit and reserving last (d-x) digit  (0<=x<=d-1)
            
            while(i<n-d){
                
                while(!dq.empty()&& s[dq.back()]>s[i]){
                    dq.pop_back();
                }
                
                dq.push_back(i);
                i++;
            }
            
            ans+=s[dq.front()];
            dq.pop_front();
            
        }
        
        return ans;
        
        
           
        
        
        
    }
};

// 150000000 723469340211 k=3
//           j           n
//           9           21
// 1570
// 4376