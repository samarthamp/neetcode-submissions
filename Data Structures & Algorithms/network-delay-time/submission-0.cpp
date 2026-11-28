class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // u -> {v, w}
        vector<vector<pair<int, int>>> graph(n+1);
        for (auto& t : times)
            graph[t[0]].push_back({t[1], t[2]});

        vector<int> minDelay(n+1, INT_MAX);
        minDelay[k] = 0;

        // min-heap of {dist-to-node, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();

            if (dist > minDelay[node]) continue;

            for (auto [v, w] : graph[node])
            {
                if (dist + w < minDelay[v])
                {
                    minDelay[v] = dist + w;
                    pq.push({minDelay[v], v});
                }
            }
        }

        int ans = *max_element(minDelay.begin() + 1, minDelay.end());

        if (ans == INT_MAX) return -1;
        return ans;
    }
};