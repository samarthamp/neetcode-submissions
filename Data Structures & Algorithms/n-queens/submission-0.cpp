class Solution {
private:
    unordered_set<int> cols;
    unordered_set<int> posd;
    unordered_set<int> negd;
    vector<vector<string>> ans;
    int N;
    vector<string> board;
public:
    vector<vector<string>> solveNQueens(int n) {
        string temp(n, '.');
        for (int i = 0; i < n; i++) board.push_back(temp);
        N = n;

        backtrack(0);
        return ans;
    }

    void backtrack(int r)
    {
        if (r == N)
        {
            vector<string> temp(board);
            ans.push_back(temp);
            return;
        }

        for (int c = 0; c < N; c++)
        {
            if (!valid(r, c)) continue;

            cols.insert(c);
            posd.insert(r + c);
            negd.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1);

            cols.erase(c);
            posd.erase(r + c);
            negd.erase(r - c);
            board[r][c] = '.';
        }
    }

    bool valid(int r, int c)
    {
        if (cols.find(c) != cols.end() ||
            posd.find(r + c) != posd.end() ||
            negd.find(r - c) != negd.end()) return false;
        return true;
    }
};