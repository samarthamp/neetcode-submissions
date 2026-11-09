class Solution {
private:
        
public:
    int numDecodings(string s) {
        int n = s.length();

        if (s[0] == '0') return 0;
        if (n == 1) return 1;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (s[i-1] == '*' || s[i-1] >= '3') return 0;
                s[i] = '*';
                s[i-1] = '*';
            }
        }   

        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '*' || s[i-1] == '*') 
            {
                dp[i] = dp[i-1];
                continue;
            }

            int increment = 1;
            if (i >= 2) increment = dp[i-2];

            if (s[i-1] == '1') dp[i] = dp[i-1] + increment;
            else if (s[i-1] == '2' && s[i] <= '6') dp[i] = dp[i-1] + increment;
            else dp[i] = dp[i-1];
        }

        return dp[n-1];
    }
};
