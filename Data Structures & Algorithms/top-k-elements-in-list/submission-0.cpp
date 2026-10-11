#define all(v) (v).begin(), (v).end()

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (auto num:nums) freq[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int curr = 0;
        for (auto [num, f]:freq)
        {
            if (curr < k) {
                pq.push({f, num});
                curr++;
            } else if (f > pq.top().first) {
                pq.pop();
                pq.push({f, num});
            }
        }

        vector<int> res;
        while (!pq.empty()) 
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(all(res));
        return res;
    }
};