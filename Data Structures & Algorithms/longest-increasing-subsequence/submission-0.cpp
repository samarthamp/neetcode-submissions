class Solution {
private:

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            int temp = 0;

            while (j >= 0) 
            {
                if (nums[j] < nums[i]) temp = max(temp, dp[j]);
                j--;
            }

            dp[i] = temp + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};