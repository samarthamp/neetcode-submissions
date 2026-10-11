class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i<n1; i++)
        {
            int idx1 = (int)(s1[i] - 'a');
            int idx2 = (int)(s2[i] - 'a');
            freq1[idx1]++;
            freq2[idx2]++;
        }

        int left = 0;
        int right = n1 - 1;

        while (right < n2)
        {
            if (found(freq1, freq2)) return true;
            freq2[(int)(s2[left] - 'a')]--;
            left++;
            right++;
            if (right < n2) freq2[(int)(s2[right] - 'a')]++;
        }
        return false;
    }

    bool found(vector<int>& freq1, vector<int>& freq2)
    {
        for (int i = 0; i<26; i++)
        {
            if (freq1[i] > freq2[i]) return false;
        }
        return true;
    }
};