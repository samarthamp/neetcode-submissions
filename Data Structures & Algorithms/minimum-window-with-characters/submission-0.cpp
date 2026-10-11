class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (n > m) return "";

        vector<int> freq1(52, 0);
        vector<int> freq2(52, 0);

        for (int i = 0; i<n; i++)
        {
            freq1[getIdx(s[i])]++;
            freq2[getIdx(t[i])]++;
        }

        int left = 0;
        int right = n-1;
        int size = INT_MAX;
        string ans = "";

        while (right < m)
        {
            if(found(freq1, freq2))
            {
                while (((freq1[getIdx(s[left])] - 1) >= freq2[getIdx(s[left])]) && (left <= right)) 
                {
                    freq1[getIdx(s[left])]--;
                    left++;
                }

                int curr = right - left + 1; 
                if (curr < size) 
                {
                    size = curr; 
                    ans = s.substr(left, curr);
                }
            }
            right++;
            if (right < m) freq1[getIdx(s[right])]++;
        }

        return ans;
    }

    int getIdx(char c)
    {
        if (c > 'Z') return (c - 'a');
        return (c - 'A') + 26;
    }

    bool found(vector<int>& freq1, vector<int>& freq2)
    {
        for (int i = 0; i<52; i++)
        {
            if (freq2[i] > freq1[i]) return false;
        }
        return true;
    }
};