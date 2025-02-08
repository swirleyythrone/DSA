class Solution {
private:
    void bfs(int node,vector<vector<int>> &isConnected, vector<int>&vis){
       queue<int> q;
       q.push(node);
       vis[node]=1;
       while(!q.empty()){
         node=q.front();
         q.pop();
         for(int i  = 0 ; i < isConnected.size() ; i++){
            if(isConnected[node][i] && !vis[i]){
                q.push(i);
                vis[i]=1;
            }
         }
       }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int V=isConnected.size();
       vector<int> vis(V);
       int c=0;
       for(int i=0 ; i < V ; i++){
         if(!vis[i]){
            c++;
            bfs(i,isConnected,vis);
         }
       }
       return c;
    }
    
};