class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n <= 1) return n;
        int ans = 1;

        int left = 0;
        int right = 0;
        vector<int> mp(300, 0);

        while ((left <= right) && (right < n))
        {
            int curr = (int)(s[right] - NULL);
            
            if (mp[curr] == 0) ans = max(ans, (right - left + 1));
        
            else if (mp[curr] > 0)
            {
                while (s[left] != s[right])
                {
                    mp[((int)(s[left] - NULL))]--;
                    left++;
                }
                mp[((int)(s[left] - NULL))]--;
                left++;

                ans = max(ans, (right - left + 1));
            }
            right++;
            mp[curr]++;
        }
        return ans;
    }
};