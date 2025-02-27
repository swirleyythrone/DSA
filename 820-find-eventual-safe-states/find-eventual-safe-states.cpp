class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false);
        int V = graph.size();
        vector<int> ans;
        vector<int> indegree(V,0);
        vector<vector<int>> graph_rev(V);
        for(int i = 0 ; i <  V ; i++){
            for(auto it: graph[i]){
                graph_rev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
           if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: graph_rev[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};