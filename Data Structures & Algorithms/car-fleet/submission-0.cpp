#define all(v) (v).begin(), (v).end()

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> arr;
        int n = position.size();

        if (n == 1) return 1;

        for (int i = 0; i < n; i++)
        {
            double time = (double)(target - position[i])/speed[i];
            arr.push_back({position[i], time});
        }

        sort(all(arr));
        int ans = 0;
        int ptr = n - 1;
        
        while (ptr >= 0)
        {
            double prev_time = arr[ptr].second;
            bool cond = false;

            while ((ptr >= 0) && (arr[ptr].second <= prev_time)) 
            {
                ptr--;
                cond = true;
            }
            ans++;
            if (!cond) ptr--;
        }
        return ans;
    }
};