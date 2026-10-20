class Solution {
private:
    int ans;
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        ans = 0;
        m = grid.size();
        n = grid[0].size();

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                dfs(grid, r, c, true);
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int r, int c, int cond)
    {
        if ((r < 0) || (r >= m) || (c < 0) || (c >=n)) return;
        if ((grid[r][c] == '*') || (grid[r][c] == '0')) return;

        if (cond) {cond = !cond; ans++;}
        grid[r][c] = '*';
        dfs(grid, r+1, c, cond);
        dfs(grid, r-1, c, cond);
        dfs(grid, r, c+1, cond);
        dfs(grid, r, c-1, cond);
    }
};