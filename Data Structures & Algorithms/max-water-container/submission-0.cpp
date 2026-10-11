class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n - 1;

        int max_area = 0;
        while (left < right)
        {
            int curr_area = (right - left) * min(heights[left], heights[right]);
            max_area = max(max_area, curr_area);

            int temp1 = 0;
            int temp2 = 0;
            if (left < right - 1)
            {
                temp1 = (right - left - 1) * min(heights[left+1], heights[right]);
            }

            else if (right > left + 1)
            {
                temp2 = (right - 1 - left) * min(heights[right-1], heights[left]);
            }

            if (temp1 > curr_area) left++;
            else if (temp2 > curr_area) right--;
            else if (heights[left] <= heights[right]) left++;
            else right--;
        }

        return max_area;
    }
};