class Solution {
private:
    int ans;
    int m, n;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ans = 0;
        m = grid.size();
        n = grid[0].size();

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                ans = max(ans, dfs(grid, r, c));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if ((r < 0) || (r >= m) || (c < 0) || (c >=n)) return 0;
        if (grid[r][c] <= 0) return 0;

        grid[r][c] = -1;
        
        return  dfs(grid, r+1, c) +
                dfs(grid, r-1, c) +
                dfs(grid, r, c+1) +
                dfs(grid, r, c-1) + 1;
    }
};