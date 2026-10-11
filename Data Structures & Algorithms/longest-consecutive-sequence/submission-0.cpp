class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (auto i:nums)
        {
            s.insert(i);
        }
        int max_len = 0;

        for (const auto& it:s)
        {
            if (!s.count(it-1))
            {
                int cnt = 0;
                int num = it;
                while(s.count(num))
                {
                    cnt++;
                    num++;
                }
                max_len = max(max_len, cnt);
            }
        }
        return max_len;
    }
};
