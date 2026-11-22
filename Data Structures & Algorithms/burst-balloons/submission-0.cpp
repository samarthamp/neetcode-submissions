class Solution {
private:
    
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        n = nums.size();

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));    

        return dfs(1, n-2, nums, dp);
    }

    int dfs(int l, int r, vector<int>& nums, vector<vector<int>>& dp)
    {
        if (l > r) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        dp[l][r] = 0;

        for (int i = l; i <= r; i++)
        {
            int coins = nums[l-1] * nums[i] * nums[r+1];
            coins += dfs(l, i-1, nums, dp) + dfs(i+1, r, nums, dp);

            dp[l][r] = max(dp[l][r], coins);
        }

        return dp[l][r];
    }
};