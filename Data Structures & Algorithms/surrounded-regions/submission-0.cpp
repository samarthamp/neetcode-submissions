class Solution {
    int m, n;
    void dfs(vector<vector<char>>& b, int r, int c) 
    {
        if (r < 0 || c < 0 || r >= m || c >= n || b[r][c] != 'O') return;
        b[r][c] = 'T';

        dfs(b, r + 1, c); dfs(b, r - 1, c);
        dfs(b, r, c + 1); dfs(b, r, c - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(); 
        n = board[0].size();

        for (int r = 0; r < m; r++) 
        { 
            dfs(board, r, 0); 
            dfs(board, r, n - 1); 
        }

        for (int c = 0; c < n; c++)
        { 
            dfs(board, 0, c); 
            dfs(board, m - 1, c); 
        }

        for (auto& row : board)
            for (char& ch : row)
                ch = (ch == 'T') ? 'O' : 'X';
    }
};