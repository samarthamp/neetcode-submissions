class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0;
        if (m > 1)
        {
            int left = 0;
            int right = m-1;
            int col = 0;

            while (left <= right)
            {
                int mid = (left+right)/2;
                if (matrix[right][col] <= target) {row = right; break;}
                else if (matrix[mid][col] > target) right = mid-1;
                else if (matrix[mid][n-1] >= target) {row = mid; break;}
                else left = mid+1;
            }
        }

        int exists = search(matrix[row], target);

        if (exists != -1) return true;
        return false;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        if (n==1) return (target == nums[0]) ? 0 : -1;

        while (left <= right)
        {
            int mid = (left + right)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};