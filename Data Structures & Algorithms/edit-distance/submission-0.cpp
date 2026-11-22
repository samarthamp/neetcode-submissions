class Solution {
private:
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        if (!len1 && !len2) return 0;
        if (!len1) return len2;
        if (!len2) return len1;

        vector<vector<int>> dp(len1+1, vector<int> (len2+1, 0));

        for (int i = 0; i <= len1; i++) dp[i][len2] = len1 - i;
        for (int j = 0; j <= len2; j++) dp[len1][j] = len2 - j;

        for (int i = len1-1; i >= 0; i--)
        {
            for (int j = len2-1; j >= 0; j--)
            {
                if (word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = 1 + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
            }
        }
        return dp[0][0];
    }
};