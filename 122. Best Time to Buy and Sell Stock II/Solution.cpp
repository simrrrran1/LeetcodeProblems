class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        // Iterate over prices starting from day 1
        for(int i = 1; i < prices.size(); i++) {
            // If price increases from previous day, we consider it a profit opportunity
            if(prices[i - 1] < prices[i])
                ans += (prices[i] - prices[i - 1]);
                // We add the profit made by buying on day i-1 and selling on day i
        }

        // Return total accumulated profit
        return ans;
    }
};
