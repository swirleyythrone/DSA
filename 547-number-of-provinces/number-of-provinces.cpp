class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, int v, vector<bool>& visited) {
        visited[v] = true;

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i] && isConnected[v][i] == 1) dfs(isConnected, i, visited);
        }
    }
  

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int V=isConnected.size();
        vector<bool> vis(V,false);

        int c=0;
        for(int i = 0 ; i < V ; i++){
          if(!vis[i]){
           dfs(isConnected,i,vis);
           c++;
          }
        }
        return c;
    }
    
};