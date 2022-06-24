struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
class Solution {
public:
unordered_map<pair<string,string>,bool,hash_pair> mp;          //Create Map Globally
    bool isScramble(string s1, string s2) {
        
        int n = s1.size();
        if(s1.size() != s2.size())          //Checking length of both string
            return false;
        // if(s1.size()==0 && s2.size()==0)    //If both strings are empty
        //     return true;
        if(s1==s2)               //If both strings are same
            return true;
        if(n<=1)                    //Check size of String s1 is less tha 1 OR not
            return false;
        
        
        if(mp.find({s1,s2}) != mp.end())        //Storing value in map if found 
            return mp[{s1,s2}];
        /*Till now if we didn't find our value then we will calculate particularly */
        // int n=s1.size();
        bool flag=false;
        for(int i=1;i<n;i++) {
            if((isScramble(s1.substr(0,i),s2.substr(n-i,i))
              && isScramble(s1.substr(i,n-i),s2.substr(0,n-i)))
                                      || 
               (isScramble(s1.substr(0,i),s2.substr(0,i))
                && isScramble(s1.substr(i,n-i),s2.substr(i,n-i)))) {
               flag = true;
                break;
            }
        }
        return mp[{s1,s2}]=flag;
    }
};