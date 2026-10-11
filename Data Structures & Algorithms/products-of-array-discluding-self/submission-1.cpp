class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> answer(n, 1);

        answer[1] = nums[0];
        
        int recurring = nums[0];
        for (int i = 2; i < n; i++)
        {
            recurring *= nums[i-1];
            answer[i] = recurring;
        }

        recurring = nums[n-1];

        for (int i = n-2; i >= 0; i--)
        {
            answer[i] *= recurring;
            recurring *= nums[i];
        }

        // for (int i = 0; i<n; i++)
        // {
        //     cout << answer[i] << " ";
        // }
        // cout << "\n";

        return answer;
    }
};
