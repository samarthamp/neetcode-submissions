class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (st.empty()) {st.push({temperatures[i], i}); continue;}

            while (temperatures[i] > st.top().first)
            {
                int idx = st.top().second;
                st.pop();

                ans[idx] = i - idx;
                if (st.empty()) break;
            }
            st.push({temperatures[i], i});
        }

        return ans;
    }
};
