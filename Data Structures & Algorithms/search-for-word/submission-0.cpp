class Solution {
private:
    int ROWS, COLS, WORD_SIZE;
public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        WORD_SIZE = word.length();

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs (vector<vector<char>>& board, int r, int c, string word, int ptr)
    {
        if ((r < 0) || (r >= ROWS) || (c < 0) || (c >= COLS)) return false;
        if (board[r][c] == '*') return false;

        if (ptr == WORD_SIZE - 1) return (board[r][c] == word[ptr]);

        if (board[r][c] != word[ptr]) return false;

        char temp = board[r][c];
        board[r][c] = '*';

        bool cond = dfs(board, r-1, c, word, ptr + 1) ||
                    dfs(board, r+1, c, word, ptr + 1) ||
                    dfs(board, r, c-1, word, ptr + 1) ||
                    dfs(board, r, c+1, word, ptr + 1);

        board[r][c] = temp;
        return cond;
    }
};