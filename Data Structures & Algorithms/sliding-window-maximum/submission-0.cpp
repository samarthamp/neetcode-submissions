class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i<k-1; i++) maxHeap.push({nums[i], i});

        int left = 0;
        int right = k-1;
        vector<int> ans;
        while (right < n)
        {
            maxHeap.push({nums[right], right});
            while (maxHeap.top().second < left) maxHeap.pop();

            ans.push_back(maxHeap.top().first);
            right++;
            left++;
        }
        return ans;
    }
};