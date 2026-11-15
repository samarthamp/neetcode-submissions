class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < 2 || sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            if (num > target) return false; // Impossible to partition if one element > half

            for (int j = target; j >= num; --j) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }

            if (dp[target]) return true; // Early exit as soon as target is reachable
        }

        return dp[target];
    }
};