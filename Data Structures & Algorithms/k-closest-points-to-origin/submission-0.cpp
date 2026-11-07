class Solution {
private:
    struct node{
        float dist;
        int x;
        int y;
    };

    struct CompareNode{
        bool operator()(const node& a, const node& b)
        {
            return a.dist < b.dist;
        }
    };

    priority_queue<node, vector<node>, CompareNode> pq;
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            float dist = sqrt((x*x) + (y*y));

            if (pq.size() == k)
            {
                if (dist < pq.top().dist)
                {
                    pq.pop();
                    pq.push({dist, x, y});
                }
            }
            else pq.push({dist, x, y});
        }

        vector<vector<int>> ans;
        while (pq.size() > 0)
        {
            auto [dist, x, y] = pq.top();
            pq.pop();
            ans.push_back({x, y});
        }

        return ans;
    }
};