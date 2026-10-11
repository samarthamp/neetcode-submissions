class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans;

        while (left <= right)
        {
            int mid = (left + right)/2;
            long long int time = calculateTime(piles, mid);

            if (time <= h) 
            {
                ans = mid;
                right = mid-1;
            }
            else if (time > h) left = mid+1;
        }

        return ans;
    }

    long long int calculateTime(vector<int>& piles, int k)
    {
        int n = piles.size();
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (piles[i]/k);
            int rem = ((piles[i] % k == 0) ? 0: 1);
            ans += rem;
        }
        return ans;
    }
};
