class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        // binary search on the smaller array so j always stays within nums2
        if (m > n) return findMedianSortedArrays(nums2, nums1);

        if (!m) return median(nums2);

        int cnt = (m + n)/2;
        int left1 = -1;
        int right1 = m-1;

        while(true)
        {
            // (left1 + right1)/2 truncates toward zero
            int i = left1 + (right1 - left1)/2;
            int j = cnt - i - 2;

            int aleft = (i >= 0) ? nums1[i] : INT_MIN;
            int aright = (i+1 < m) ? nums1[i+1] : INT_MAX;
            int bleft = (j >= 0) ? nums2[j] : INT_MIN;
            int bright = (j+1 < n) ? nums2[j+1] : INT_MAX;

            if ((aleft <= bright) && (bleft <= aright))
            {
                if ((m+n)%2)
                {
                    // odd
                    double ans = min(aright, bright);
                    return ans;
                }
                else
                {
                    // even
                    double ans = ((double)max(aleft, bleft) + min(aright, bright))/2;
                    return ans;
                }
            }
            else if (aleft > bright) right1 = i - 1;
            else left1 = i + 1;
        }
        return 0;
    }

    double median(vector<int>& nums)
    {
        int n = nums.size();
        if (n%2 == 0) return (double)(nums[n/2] + nums[(n/2) - 1])/2;
        else return nums[n/2];
    }
};