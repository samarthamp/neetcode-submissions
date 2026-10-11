#define all(v) (v).begin(), (v).end()

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(all(nums));
        int n = nums.size();
        int ptr = 0;
        
        vector<vector<int>> ans;

        while (ptr < n-2)
        {
            int target = 0 - nums[ptr];
            int right = n - 1;
            int left = ptr + 1;
            
            while (left < right)
            {
                if (nums[left] + nums[right] == target)
                {
                    ans.push_back({nums[ptr], nums[left], nums[right]});
                    left = seek_ptrs(nums, left, right);
                }
                else if (nums[left] + nums[right] > target) 
                {
                    int temp = nums[right];
                    while ((nums[right] == temp) && right > left) right--;
                }
                else left++;
            }

            int prev = nums[ptr];
            ptr = seek_ptrs(nums, ptr, n-2);
        }

        return ans;
    }

    int seek_ptrs(const vector<int> nums, int ptr, int limit)
    {
        int temp = nums[ptr];
        while ((nums[ptr] == temp) && ptr < limit) ptr++;

        return ptr;
    }
};
