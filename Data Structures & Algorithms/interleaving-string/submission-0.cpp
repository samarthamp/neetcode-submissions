class Solution {
private:
    int len1, len2, len3;
    string S1, S2, S3;
public:
    bool isInterleave(string s1, string s2, string s3) {
        len1 = s1.size();
        len2 = s2.size();
        len3 = s3.size();
        cout << len1 << " " << len2 << " " << len3 << "\n";

        if (len3 != len1 + len2) return false;

        if (!len1) return s2 == s3;
        if (!len2) return s1 == s3;

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, -1));

        S1 = s1;
        S2 = s2;
        S3 = s3;

        return dfs(1, 0, dp, 1, 0) || dfs(0, 1, dp, 2, 0);
    }

    bool dfs(int x, int y, vector<vector<int>>& dp, int dir, int idx)
    {
        if (x > len1 || y > len2) return false;

        if (x == len1 && y == len2)
        {
            if (dir == 1 && S1[x-1] == S3[idx])
            {
                dp[x][y] = 1;
                return true;
            }
            else if (dir == 2 && S2[y-1] == S3[idx])
            {
                dp[x][y] = 1;
                return true;
            }

            dp[x][y] = 0;
            return false;
        }

        if (dp[x][y] != -1) return dp[x][y] == 1 ? true : false;

        if (dir == 1)
        {
            if (S1[x-1] == S3[idx])
            {
                if (dfs(x+1, y, dp, 1, idx+1) || dfs(x, y+1, dp, 2, idx+1))
                {
                    dp[x][y] = 1;
                    return true;
                }
            }

            dp[x][y] = 0;
            return false;
        }

        else
        {
            if (S2[y-1] == S3[idx])
            {
                if (dfs(x+1, y, dp, 1, idx+1) || dfs(x, y+1, dp, 2, idx+1))
                {
                    dp[x][y] = 1;
                    return true;
                }
            }

            dp[x][y] = 0;
            return false;
        }
    }
};