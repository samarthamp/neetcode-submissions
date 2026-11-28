#define all(v) (v).begin(), (v).end()

class Solution {
private:
    unordered_map<string, vector<string>> graph;
    vector<string> route;

    void dfs(const string& src)
    {
        auto& adj = graph[src];
        while (!adj.empty())
        {
            string next = adj.back();
            adj.pop_back();
            dfs(next);
        }
        route.push_back(src);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // sort descending so each adjacency list ends with its smallest destination
        sort(tickets.rbegin(), tickets.rend());
        for (auto& t : tickets) graph[t[0]].push_back(t[1]);

        dfs("JFK");
        reverse(all(route));
        return route;
    }
};