class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        
        
        queue<pair<int,int>>q;
        
        vector<int>f(26,0);
        
        for(auto k:tasks){
            
            f[k-'A']++;
        }
        
        
        
        priority_queue<int>pq;
        
        for(int i=0;i<26;i++){
            
            if(f[i])
            pq.push(f[i]);
        }
        
        int time=0;
        
        while(!pq.empty()||!q.empty()){
            
            time++;
            
           if(!pq.empty()){
               
               int x = pq.top();
               pq.pop();
               
               if(x-1>0)
               q.push({x-1,time+n});
               
           }
            
         if(time==q.front().second){
             pq.push(q.front().first);
             q.pop();
         }
           
            
            
        }
        
        return time;
        
    }
};