class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis,
             vector<vector<char>>& board, int n, int m) {
        vis[r][c] = 1;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nr = r + drow[k];
            int nc = c + dcol[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                board[nr][nc] == 'O') {
                dfs(nr, nc, vis, board, n, m);
            }
        }
    }
    // OR DFS FUnc
    void dfs2(int r, int c, vector<vector<int>>& vis,
              vector<vector<char>>& board, int n, int m) {
        // out of bounds
        if (r < 0 || c < 0 || r >= n || c >= m)
            return;

        // already visited or not 'O'
        if (vis[r][c] || board[r][c] != 'O')
            return;

        vis[r][c] = 1;

        dfs(r + 1, c, vis, board, n, m);
        dfs(r - 1, c, vis, board, n, m);
        dfs(r, c + 1, vis, board, n, m);
        dfs(r, c - 1, vis, board, n, m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // top and bottom rows
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, vis, board, n, m);
            }
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                dfs(n - 1, j, vis, board, n, m);
            }
        }

        // left and right columns
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, vis, board, n, m);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(i, m - 1, vis, board, n, m);
            }
        }

        // flip all unvisited 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
