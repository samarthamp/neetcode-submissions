class Solution {
private:
    vector<vector<int>> ans;
    vector<int> curr;
    int curr_sum;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        curr_sum = 0;
        backtrack(candidates, target, 0);

        return ans;
    }

    void backtrack(vector<int>& nums, int target, int idx)
    {
        if (curr_sum == target) 
        {
            vector<int> temp(curr);
            ans.push_back(temp);
            return;
        }

        if ((idx >= nums.size()) || (curr_sum > target)) return;

        // repeat the same element
        curr.push_back(nums[idx]);
        curr_sum += nums[idx];
        backtrack(nums, target, idx);

        // add next element
        curr.pop_back();
        curr_sum -= nums[idx];
        backtrack(nums, target, idx+1);

        return;
    }
};