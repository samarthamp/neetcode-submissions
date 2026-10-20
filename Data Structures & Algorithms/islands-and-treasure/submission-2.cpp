class Solution {
private:
    int m, n;
    queue<pair<int, int>> q;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == 0) q.push({r, c});
            }
        }

        int curr = 0;
        while (!q.empty())
        {
            int num = q.size();
            for (int i = 0; i < num; i++)
            {
                auto [r, c] = q.front();
                q.pop();
                addCell(grid, r+1, c, curr+1);
                addCell(grid, r-1, c, curr+1);
                addCell(grid, r, c+1, curr+1);
                addCell(grid, r, c-1, curr+1);
            }
            curr++;
        }
    }

    void addCell(vector<vector<int>>& grid, int r, int c, int dist)
    {
        if ((r < 0) || (r >= m) || (c < 0) || (c >=n)) return;
        if (grid[r][c] != INT_MAX) return;

        grid[r][c] = dist;
        q.push({r, c});
    }
};