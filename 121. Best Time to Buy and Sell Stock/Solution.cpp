class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = INT_MIN;
        int minD = INT_MAX;

        for(int i=0; i<prices.size(); i++){
            minD = min(minD, prices[i]);
            maxP = max(maxP, prices[i] - minD);
        }
        return maxP;
    }
};