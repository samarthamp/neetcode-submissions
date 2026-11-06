class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<int, Node*> mp;
    int N;
    int ans;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int numEdges = edges.size();
        N = n;
        ans = 0;
        if (numEdges < 1) return true;

        for (int i = 0; i < numEdges; i++)
        {
            int ai = edges[i][0];
            int bi = edges[i][1];

            if (mp.find(ai) == mp.end())
            {
                auto temp = new Node(ai);
                mp[ai] = temp;
            }

            if (mp.find(bi) == mp.end())
            {
                auto temp = new Node(bi);
                mp[bi] = temp;
            }

            mp[ai]->neighbors.push_back(mp[bi]);
            mp[bi]->neighbors.push_back(mp[ai]);
        }

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) 
        {
            if (mp[i]) dfs(mp[i], visited, -1);
            else ans++;
        }
        return ans;
    }

    void dfs(Node* root, vector<int> & visited, int parent)
    {
        int curr = root->val;
        if (visited[curr] == 1) return;

        visited[curr] = 1;

        int num_next = root->neighbors.size();

        bool cond = true;
        for (int i = 0; i < num_next; i++) 
        {
            if (visited[root->neighbors[i]->val]) continue;
            dfs(root->neighbors[i], visited, curr);
        }

        root->neighbors = vector<Node*>();
        if (parent == -1) ans++;

        return;
    }
};