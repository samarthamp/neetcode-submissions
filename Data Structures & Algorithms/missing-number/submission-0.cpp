class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ref = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++) ref = ref^i;

        int given = 0;
        for (auto i : nums) given = given^i;

        return ref^given;
    }
};