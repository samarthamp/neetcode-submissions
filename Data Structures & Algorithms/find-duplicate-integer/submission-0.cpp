class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n==2) return nums[0];

        int slow = 0;
        int fast = 0;
        bool cond = false;
    
        while (!cond)
        {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if (slow == fast) cond = true;
        }
        int ptr1 = 0;
        int ptr2 = slow;

        while (ptr1 != ptr2)
        {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
};