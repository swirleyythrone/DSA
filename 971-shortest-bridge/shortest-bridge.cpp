class Solution {
public:
    int n, m;
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};

    void dfs(int i, int j, vector<vector<int>>& grid, set<pair<int, int>>& vis) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis.find({i, j}) != vis.end())
            return;
        vis.insert({i, j});
        for (int d = 0; d < 4; d++) {
            int ni = i + dr[d];
            int nj = j + dc[d];
            dfs(ni, nj, grid, vis);
        }
    }

    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& vis) {
        queue<pair<int, int>> q;
        for (auto& it : vis) {
            q.push(it);
        }

        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int ni = x + dr[d];
                    int nj = y + dc[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && vis.find({ni, nj}) == vis.end()) {
                        if (grid[ni][nj] == 1) {
                            return level;
                        }
                        vis.insert({ni, nj});
                        q.push({ni, nj});
                    }
                }
            }
            level++;
        }
        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        set<pair<int, int>> vis;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, vis);
                    return bfs(grid, vis);
                }
            }
        }

        return -1;
    }
};
