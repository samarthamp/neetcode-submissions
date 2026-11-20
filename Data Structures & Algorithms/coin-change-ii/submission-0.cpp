class Solution {
private:
        
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<unsigned int> dp(amount+1, 0);
        dp[0] = 1;
        for (int c : coins)
            for (int a = c; a <= amount; a++)
                dp[a] += dp[a - c];

        return dp[amount];
    }
};