class Solution {
private:
    void bfs(int node,vector<vector<int>> &isConnected,vector<int> &vis){
        queue<int> q;
        q.push(node);
        vis[0]=1;
        while(!q.empty()){
            node =q.front();
            q.pop();
            for(int i = 0;i < isConnected.size() ; i++){
                if(isConnected[node][i] && !vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int c =0;
        vector<int> vis(n,0);
        for(int i= 0 ;i< n ; i++){
            if(!vis[i]){
                c++;
                bfs(i,isConnected,vis);
            }
        }
        return c;
    }
};