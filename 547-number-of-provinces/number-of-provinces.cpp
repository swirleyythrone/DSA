class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
          vis[node]=1;
          for(int i = 0 ; i < adj.size() ; i++){
             if(adj[node][i]==1 && !vis[i])dfs(i,adj,vis);
          } 
    }
   int findCircleNum(vector<vector<int>>& isConnected) {
        int c = 0;
        int n = isConnected.size();
        vector<int> vis(n,0);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                c+=1;
                dfs(i,isConnected,vis);
            }
        }
        return c;
    }
};