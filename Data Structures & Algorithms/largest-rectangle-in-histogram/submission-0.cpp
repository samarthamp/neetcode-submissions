class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1) return heights[0];
        stack<pair<int, int>> st;

        int max_area = 0;

        for (int i = 0; i < n; i++)
        {
            if (st.empty()) st.push({i, heights[i]});
            else if (heights[i] >= st.top().second) st.push({i, heights[i]});
            else
            {
                int temp_idx = -1;
                while ((!st.empty()) && (heights[i] < st.top().second))
                {
                    int area = (i - st.top().first) * st.top().second;
                    temp_idx = st.top().first;
                    max_area = max(max_area, area);
                    st.pop();
                }
                if (temp_idx != -1) st.push({temp_idx, heights[i]});
                st.push({i, heights[i]});
            }
        }

        while(!st.empty())
        {
            int area = (n - st.top().first) * st.top().second;
            max_area = max(max_area, area);
            st.pop();
        }
        return max_area;
    }
};