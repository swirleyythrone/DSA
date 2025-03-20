class Solution {
private:
    void dfs(int node,vector<vector<int>> &isConnected,vector<int>&vis,vector<int> &ls){
        if(vis[node])return;
        vis[node]=1;
        for(int j = 0 ; j < isConnected[node].size(); j++){
            if(isConnected[node][j] && !vis[j]){
                dfs(j,isConnected,vis,ls);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int c =0;
        vector<int> vis(n,0);
        vector<int> ls;
        for(int i= 0 ;i< n ; i++){
            if(!vis[i]){
                c++;
                dfs(i,isConnected,vis,ls);
            }
        }
        return c;
    }
};