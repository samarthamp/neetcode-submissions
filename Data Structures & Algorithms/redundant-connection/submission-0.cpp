class Solution {
private:
    int N;
    vector<int> parent;
    vector<int> rank;
    vector<int> ans;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numEdges = edges.size();
        N = numEdges;

        for (int i = 0; i <= N; i++) {parent.push_back(i); rank.push_back(1);}

        for (int i = 0; i < N; i++)
        {
            if (!_union(edges[i][0], edges[i][1])) return ans;
        }

        return {0, 0};
    }

    int _find(int child)
    {
        if (parent[child] == child) return child;
        return _find(parent[child]);
    }

    bool _union(int c1, int c2)
    {
        int p1 = _find(c1);
        int p2 = _find(c2);

        if (p1 == p2)
        {
            ans.push_back(c1);
            ans.push_back(c2);
            return false;
        }

        if (rank[p1] >= rank[p2])
        {
            parent[p2] = p1;
            rank[p1] += rank[p2];
            return true;
        }

        else
        {
            parent[p1] = p2;
            rank[p2] += rank[p1];
            return true;
        }
    }
};
