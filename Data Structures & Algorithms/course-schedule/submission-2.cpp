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

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int numPrereq = prerequisites.size();

        if (numPrereq == 0) return true;

        for (int i = 0; i < numPrereq; i++)
        {
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];

            if (ai == bi) return false;

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
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            if (mp[i]) 
            {
                if (!dfs(mp[i], visited)) return false;
            }
        }
        return true;
    }

    bool dfs(Node* root, vector<int> & visited)
    {
        int curr = root->val;
        if (visited[curr] == 1) return false;

        visited[curr] = 1;
        int num_next = root->neighbors.size();

        bool cond = true;
        for (int i = 0; i < num_next; i++)
        {
            if (!dfs(root->neighbors[i], visited)) {cond = false; break;}
        }
        root->neighbors = vector<Node*>();
        visited[curr] = 0;
        return cond;
    }
};