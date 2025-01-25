class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuy = prices[0];
        int n = prices.size();
        for(int i = 0; i  < n; i++){
            int cost =  prices[i] - minBuy;
            maxProfit = max(maxProfit, cost);
            minBuy = min(minBuy, prices[i]);
        }
        return maxProfit;
    }
};