class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if (n==1) return 1;

        int left = 0;
        int right = 0;
        vector<int> freq(26, 0);

        int ans = 1;
        while ((left <= right) && (right < n))
        {
            freq[s[right] - 'A']++;
            // int maxFreq, maxIdx;
            auto [maxFreq, maxIdx] = maxEle(freq);

            int currEle = right - left + 1;
            int others = currEle - maxFreq;
    
            while (others > k)
            {
                freq[s[left] - 'A']--;
                left++;
                auto [maxFreq, maxIdx] = maxEle(freq);
                currEle = right - left + 1;
                others = currEle - maxFreq;
            }
            ans = max(ans, currEle);  
            right++;
        }
        return ans;
    }
    pair<int, int> maxEle(vector<int> freq)
    {
        int maxFreq = 0;
        int maxIdx = 0;
        for (int i = 0; i<26; i++)
        {
            if (freq[i] > maxFreq) {maxFreq = freq[i]; maxIdx = i;}
        }
        return {maxFreq, maxIdx};
    }
};
