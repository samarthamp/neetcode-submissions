class Solution {
private:
    vector<vector<int>> ans;
    vector<int> curr;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }

    void backtrack(vector<int>& nums,int idx)
    {
        if (idx >= nums.size()) 
        {
            vector<int> temp(curr);
            ans.push_back(temp);
            return;
        }

        curr.push_back(nums[idx]);
        backtrack(nums, idx+1);

        curr.erase(curr.end() - 1);
        backtrack(nums, idx+1);

        return;
    }
};

