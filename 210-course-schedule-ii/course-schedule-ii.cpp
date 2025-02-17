class Solution {
private:
    bool dfs(vector<vector<int>>& pre_list, int node, vector<int>& vis, vector<int>& ans) {
        if (vis[node] == 1) return true;  // Cycle detected
        if (vis[node] == 2) return false; // Already processed

        vis[node] = 1;
        for (int it : pre_list[node]) {
            if (dfs(pre_list, it, vis, ans)) return true;
        }

        vis[node] = 2;
        ans.push_back(node);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        
        vector<vector<int>> pre_list(numCourses);
        for (const auto& it : prerequisites) {
            pre_list[it[0]].push_back(it[1]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(pre_list, i, vis, ans)) return {}; // Cycle detected
            }
        }

        return ans;
    }
};
