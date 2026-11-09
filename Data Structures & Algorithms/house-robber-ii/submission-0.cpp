class Solution {
private:
        
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        auto nums1(nums);
        nums1.erase(nums1.begin());

        int a = _rob(nums1);

        auto nums2(nums);
        nums2.erase(nums2.begin() + n - 1);

        int b = _rob(nums2);

        return max(a, b);
    }

    int _rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (i < 2) dp[i] = max(nums[i], nums[0]);
            else dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[n-1];
    }
};