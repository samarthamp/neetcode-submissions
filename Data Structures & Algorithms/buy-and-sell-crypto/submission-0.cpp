class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        if (n == 1) return 0;

        int buy = 0;    
        int sell = 1;
        
        while ((buy < sell) && (sell < n))
        {
            int currProfit = prices[sell] - prices[buy];
            ans = max(ans, currProfit);
            if (currProfit < 0) buy = sell;
            sell++;
        }

        return ans;
    }
};