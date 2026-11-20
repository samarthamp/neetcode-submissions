#define all(v) (v).begin(), (v).end()

class Solution {
private:
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = accumulate(all(nums), 0);
        if (abs(target) > S || (S + target) % 2 != 0) return 0;

        int P = (S + target) / 2;
        vector<int> dp(P + 1, 0);
        dp[0] = 1;

        for (int x : nums)
            for (int a = P; a >= x; a--)
                dp[a] += dp[a - x];

        return dp[P];
    }
};