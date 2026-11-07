class Solution {
private:
    unordered_map<char, int> mp;

    struct Node{
        char task;
        int freq;
        int activation_time;
    };

    struct CompareNode{
        bool operator()(const Node& a, const Node& b)
        {
            if (a.activation_time == b.activation_time) return a.freq < b.freq;
            return a.activation_time > b.activation_time;
        }
    };

    priority_queue<Node, vector<Node>, CompareNode> pq;

public:
    int leastInterval(vector<char>& tasks, int n) {
        int numTasks = tasks.size();

        for (int i = 0; i < numTasks; i++) mp[tasks[i]]++;
        
        for (auto it : mp) pq.push({it.first, it.second, 0});
        
        int curr = 0;

        while (pq.size() > 0)
        {
            auto process = pq.top();
            if (process.activation_time <= curr)
            {
                pq.pop();
                process.freq--;
                process.activation_time += n + 1;

                if (process.freq > 0) pq.push(process);
            }
            curr++;
        }
        return curr;
    }
};