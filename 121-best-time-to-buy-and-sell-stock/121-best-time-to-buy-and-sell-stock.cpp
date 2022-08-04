class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], profit = 0;
        
        for(int i = 1;i < prices.size();i++) {
            if(prices[i] < min) min = prices[i];
            
            if(profit < prices[i] - min) profit = prices[i] - min;
        }
        
        return profit;
    }
};