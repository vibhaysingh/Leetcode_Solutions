class Solution {
public:
    string getPermutation(int n, int k) {
        
        // for n=4
        // ttl permutation -->24        
        // 1 +{ 2,3 4} -->6
        // 2 +{ 1,3 4} -->6
        // 3 +{ 2,1 4} -->6
        // 4 +{ 2,3 1} -->6        
        //  suppose k==14        
        // so first numsber will be (14/6 +1) but if it is completely divisible do not add 1
        // for 14 we get first number as 3
        // so our ans will lie in  3 +{ 2,1 4}
        // for next digit
        // now again   1+ {2,4} --> 2
         //            2+ {1,4} --> 2
         //            4 + {1 2} -->2
        // but now k will become (14 - 12)  as we have dropped 12 permutation k==2 now
        
        // now it woule be k/2==1 (do not add 1 if it is completely divisible)
        
         // ans="31"
         // 2+ {4} -->1
         // 4 + {2} -->1
        // k wil be still 2 as no permutation dropped
        // k/1 == 2/1 == 2nd pateern ie 4+ {2}
        // ans = "314";
        // 2 + {}--> && k will be (2-1) as we have dropped 1 permutation from previous one
        //  ans="3142"
        
        string ans="";
        
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        
        vector<int>f(n+1);
        f[0]=1;
        for(int i=1;i<=n;i++){
            
            f[i]=f[i-1]*i;
        }
        
        int l = n;
        
        while(ans.size()<l){
           
            int oneset = f[n]/n;
            int chosenset = k/oneset;            
            if(k%oneset) chosenset++;
            // cout<<chosenset<<" "<<k<<endl;
            ans+=(to_string(v[chosenset-1]));
            v.erase(find(v.begin(),v.end(),v[chosenset-1]));
            int permdropped = oneset*(chosenset-1);
            
            // cout<<permdropped<<endl;
            
            k = k - permdropped;
            n--;
            
        
            
            
            
            
            
        }
        
        return ans;
    }
};