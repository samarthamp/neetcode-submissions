#define all(v) (v).begin(), (v).end()
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> curr;
    int curr_sum;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums(candidates);
        sort(all(nums));

        backtrack(nums, target, 0);
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
        backtrack(nums, target, idx+1);

        // add next element
        curr.pop_back();
        curr_sum -= nums[idx];
        int prev = nums[idx];
        
        while((idx < nums.size()) && (nums[idx] == prev)) idx++;

        backtrack(nums, target, idx);

        return;
    }
};