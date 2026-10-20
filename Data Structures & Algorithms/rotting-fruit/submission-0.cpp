class Solution {
private:
    int m, n;
    queue<pair<int, int>> q;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == 2) q.push({r, c});
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
                addCell(grid, r+1, c);
                addCell(grid, r-1, c);
                addCell(grid, r, c+1);
                addCell(grid, r, c-1);
            }
            if (num) curr++;
        }
        
        if (curr) curr--;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == 1) return -1;
            }
        }
        return curr;
    }

    void addCell(vector<vector<int>>& grid, int r, int c)
    {
        if ((r < 0) || (r >= m) || (c < 0) || (c >=n)) return;
        if (grid[r][c] != 1) return;

        grid[r][c] = 2;
        q.push({r, c});
    }
};