class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        board[row][col] = '#';  // Mark as safe

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Step 1: Mark boundary-connected 'O's as '#'
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board);
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
        }

        // Step 2: Convert all remaining 'O's to 'X' (they are surrounded)
        // Convert '#' back to 'O' (these are safe)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
