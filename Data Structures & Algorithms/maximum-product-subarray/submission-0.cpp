class Solution {
private:
        
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int curMin = 1, curMax = 1;

        for (auto &x : nums)
        {
            int temp = curMax * x;
            curMax = max({temp, curMin * x, x});
            curMin = min({temp, curMin * x, x});
            ans = max(ans, curMax);
        }
        return ans;
    }
};