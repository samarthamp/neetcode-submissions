class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (pq.size() == k)
            {
                if (nums[i] > pq.top())
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            else pq.push(nums[i]);
        }

        return pq.top();
    }
};