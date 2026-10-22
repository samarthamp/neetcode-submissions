struct PairHash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

class Solution {
private:
    int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        unordered_set<pair<int, int>, PairHash> pac;
        unordered_set<pair<int, int>, PairHash> atl;

        for (int c = 0; c < n; c++)
        {
            dfs(0, c, heights, pac, heights[0][c]);
            dfs(m-1, c, heights, atl, heights[m-1][c]);
        }

        for (int r = 0; r < m; r++)
        {
            dfs(r, 0, heights, pac, heights[r][0]);
            dfs(r, n-1, heights, atl, heights[r][n-1]);
        }
        
        vector<vector<int>> ans;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if ((pac.find({r,c}) != pac.end()) && (atl.find({r, c}) != atl.end())) ans.push_back({r, c});
            }
        }
        return ans;
    }

    void dfs(int r, int c, vector<vector<int>>& heights, unordered_set<pair<int, int>, PairHash>& visit, int prev)
    {
        if ((visit.find({r, c}) != visit.end()) || (r < 0) ||
        (r >= m) || (c < 0) || (c >= n) || (heights[r][c] < prev)) return;

        visit.insert({r, c});
        dfs(r+1, c, heights, visit, heights[r][c]);
        dfs(r, c+1, heights, visit, heights[r][c]);
        dfs(r-1, c, heights, visit, heights[r][c]);
        dfs(r, c-1, heights, visit, heights[r][c]);
    }   

};