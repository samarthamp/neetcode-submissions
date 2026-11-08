class Solution {
private:
        
public:
    int climbStairs(int n) {
        vector<int> arr(n + 1, 0);

        arr[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (i >= 1)
            {
                arr[i] += arr[i - 1];
            }

            if (i >= 2)
            {
                arr[i] += arr[i - 2];
            }
        }
        return arr[n];
    }
};