class Solution {
private:
        
public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n == 1) return 1;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                ans++;
                l--;
                r++;
            }

            // even length
            l = i, r = i+1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                ans++;
                l--;
                r++;
            }
        }

        return ans;
    }
};