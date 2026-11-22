class Solution {
private:
    int ans = 0;
    int len1, len2;
    string S, T;
public:
    int numDistinct(string s, string t) {
        len1 = s.length();
        len2 = t.length();
        S = s;
        T = t;

        vector<vector<int>> dp(len1, vector<int>(len2, -1));

        return dfs(0, 0, dp);
    }

    int dfs(int x, int y, vector<vector<int>>& dp)
    {
        if (x >= len1 || y >= len2) return 0;

        if (dp[x][y] != -1) return dp[x][y];

        if (S[x] != T[y])  dp[x][y] = 0;
        else
        {
            if (y == len2 - 1) dp[x][y] = 1;
            else dp[x][y] = dfs(x+1, y+1, dp);
        }

        dp[x][y] += dfs(x+1, y, dp);

        return dp[x][y];
    }
};