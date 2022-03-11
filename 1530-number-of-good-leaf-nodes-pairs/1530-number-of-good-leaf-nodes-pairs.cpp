/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode* , vector<TreeNode*> > adj;
    
    vector<TreeNode*>leaves;
    
    void constructGraph(TreeNode* root){
        
        if(!root) return;
         
        
        constructGraph(root->left);
        
         if (!root->left && !root->right)
            leaves.push_back(root);
        
        if(root->left){
            
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
        }
        
       if(root->right){
            
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
        }
        
         constructGraph(root->right);
    }
    
    int ans=0;
    
    void bfs(TreeNode* leaf, int distance){
        
        queue<TreeNode*>q;
        
        // cout<<leaf->val<<endl;
        
        q.push(leaf);
        
        unordered_map<TreeNode*, bool > vis;
        
        int dist=0;
        
        while(!q.empty()){
            
            int l = q.size();
            
            for(int i=0;i<l;i++){
                
                auto k = q.front();
                q.pop();
                
                if(vis[k]) continue;
                
                // cout<<k->val<<endl;
                
                if(k!=leaf &&  !k->left && !k->right)
                    ans++;
                
                
                vis[k]=true;
                
                for(auto j:adj[k]){
                    q.push(j);
                }
            }
            
            dist++;            
            if(dist>distance) return;
        }
        
        
    }
    
    int countPairs(TreeNode* root, int distance) {
        
        adj.clear();
        leaves.clear();
        ans=0;
        
        constructGraph(root);
        
       
        
        for(auto k:leaves){
            bfs(k,distance);
        }
        
        return ans/2;
    }
};