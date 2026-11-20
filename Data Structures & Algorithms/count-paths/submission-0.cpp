class Solution {
private:
    int M, N;
public:
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(0, 0, dp);
    }

    int dfs(int x, int y, vector<vector<int>>& dp)
    {
        if (x >= M || y >= N) return 0;
        
        if (x == M - 1 && y == N - 1) dp[x][y] = 1;

        if (dp[x][y] == -1) dp[x][y] = dfs(x+1, y, dp) + dfs(x, y+1, dp);
    
        return dp[x][y];
    }
};