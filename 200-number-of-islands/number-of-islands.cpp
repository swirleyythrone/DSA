class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '0';  // Mark as visited

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [curRow, curCol] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = curRow + drow[k];
                int ncol = curCol + dcol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1') {
                    grid[nrow][ncol] = '0';  // Mark as visited
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '1') {
                    count++;
                    bfs(row, col, grid);
                }
            }
        }
        return count;
    }
};
