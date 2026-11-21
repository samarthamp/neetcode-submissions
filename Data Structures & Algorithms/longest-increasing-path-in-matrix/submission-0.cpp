class Solution {
private:
    int m, n;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(i, j, -1, matrix, dp));

        // for (int i = 0; i < m; i++) print_vector(dp[i]);

        return ans;
    }

    int dfs(int x, int y, int parent, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if (x < 0 || x >= m || y < 0 || y >= n) return 0;
        if (matrix[x][y] <= parent) return 0;
        if (dp[x][y] != -1) return dp[x][y];

        int curr = 1;
        curr = max(curr, 1 + dfs(x+1, y, matrix[x][y], matrix, dp));
        curr = max(curr, 1 + dfs(x-1, y, matrix[x][y], matrix, dp));
        curr = max(curr, 1 + dfs(x, y+1, matrix[x][y], matrix, dp));
        curr = max(curr, 1 + dfs(x, y-1, matrix[x][y], matrix, dp));

        dp[x][y] = curr;
        
        return curr;
    }
};