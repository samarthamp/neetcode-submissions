class Solution {
private:
        
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;

        int n = stones.size();
        for (int i = 0; i < n; i++) maxheap.push(stones[i]);

        while (maxheap.size() > 1)
        {
            int y = maxheap.top();
            maxheap.pop();
            int x = maxheap.top();
            maxheap.pop();

            if (y == x) continue;
            else maxheap.push(y - x);
        }

        if (!maxheap.size()) return 0;
        
        return maxheap.top();
    }
};