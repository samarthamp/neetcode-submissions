class Solution {
private:
        
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;

        string ans;
        int ansLen = 0;

        for (int i = 0; i < n; i++)
        {
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > ansLen)
                {
                    ans = s.substr(l, r - l + 1);
                    ansLen = r - l + 1;
                }
                l--;
                r++;
            }

            // even length
            l = i, r = i+1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > ansLen)
                {
                    ans = s.substr(l, r - l + 1);
                    ansLen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};