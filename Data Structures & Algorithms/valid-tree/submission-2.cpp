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
    unordered_set<int> st;
    int N;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int numEdges = edges.size();
        N = n;
        if (numEdges <= 1) return true;

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
            int count = 0;
            if (mp[i] && (!st.count(i))) 
            {
                if (!dfs(mp[i], visited, -1, count)) return false;
            }
        }
        return true;
    }

    bool dfs(Node* root, vector<int> & visited, int parent, int & count)
    {
        int curr = root->val;
        if (visited[curr] == 1) return false;

        visited[curr] = 1;
        count++;

        int num_next = root->neighbors.size();

        bool cond = true;
        for (int i = 0; i < num_next; i++) 
        {
            if (st.count(root->neighbors[i]->val) || (root->neighbors[i]->val == parent)) continue;
            if (!dfs(root->neighbors[i], visited, curr, count)) {cond = false; break;}
        }
        root->neighbors = vector<Node*>();
        visited[curr] = 0;

        if (cond && (!st.count(root->val))) st.insert(root->val);
        if (parent == -1 && count != N) cond = false;
        
        return cond;
    }
};