class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (minheap.size() == k)
            {
                if (nums[i] > minheap.top())
                {
                    minheap.pop();
                    minheap.push(nums[i]);
                }
            }
            else minheap.push(nums[i]);
        }
        return;
    }
    
    int add(int val) {
        if (minheap.size() == K)
        {
            if (val > minheap.top())
            {
                minheap.pop();
                minheap.push(val);
            }
        }
        else minheap.push(val);
        return minheap.top();
    }
};