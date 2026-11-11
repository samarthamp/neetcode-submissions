class Solution {
private:
        
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = s.length();

        for (auto& x: wordDict) st.insert(x);

        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (auto& word : st)
            {
                int wlen = word.length();
                if ((i + wlen <= n) && s.substr(i, wlen) == word) dp[i] = dp[i + wlen];
                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};