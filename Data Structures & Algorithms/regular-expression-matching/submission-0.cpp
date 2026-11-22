class Solution {
private:
    int len1, len2;
    string S, P;
    map<pair<int, int>, int> cache;
public:
    bool isMatch(string s, string p) {
        len1 = s.size();
        len2 = p.size();

        if (s == p) return true;
        S = s; P = p;

        return dfs(0, 0);
    }

    bool dfs(int i, int j)
    {
        if (cache.count({i, j})) return cache[{i, j}];

        if (i >= len1 && j >= len2) return true;

        if (j >= len2) return false;

        bool match = (i < len1) && (S[i] == P[j] || P[j] == '.');

        if ((j + 1 < len2) && P[j+1] == '*')
        {
            cache[{i, j}] = dfs(i, j+2) || (match && dfs(i+1, j));
            return cache[{i, j}];
        }

        if (match)
        {
            cache[{i, j}] = dfs(i+1, j+1);
            return cache[{i, j}];
        }
        cache[{i, j}] = false;
        return false;
    }
};