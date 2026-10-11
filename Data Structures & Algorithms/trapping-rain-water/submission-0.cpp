class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ptr = 1;

        vector<int> pre_larger(n, 0);
        vector<int> post_larger(n, 0);
        int ans = 0;

        for (int i = 1; i < n; i++)
        {
            pre_larger[i] = max(height[i-1], pre_larger[i-1]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            post_larger[i] = max(height[i+1], post_larger[i+1]);
        }

        while (ptr < n-1)
        {
            if (height[ptr] < min(pre_larger[ptr], post_larger[ptr]))
            {
                ans += min(pre_larger[ptr], post_larger[ptr]) - height[ptr];
            }
            ptr++;
        }

        return ans;
    }
};