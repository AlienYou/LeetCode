class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX, maxPro = 0;
        for (int i = 0; i < prices.size(); ++i) {
            minVal = min(prices[i], minVal);
            maxPro = max(maxPro, prices[i] - minVal);
        }
        return maxPro;
    }
};