class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while (left <= right)
        {
            int mid = (left+right)/2;

            if ((nums[left] <= nums[mid]) && (nums[mid] <= nums[right])) return nums[left];
            else if ((nums[left] <= nums[mid]) && (nums[mid] >= nums[right])) left = mid+1;
            else if ((nums[left] >= nums[mid]) && (nums[mid] <= nums[right])) right = mid;
        }
    }
};