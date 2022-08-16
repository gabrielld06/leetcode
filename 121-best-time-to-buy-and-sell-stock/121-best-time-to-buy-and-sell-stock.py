class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        low, profit = prices[0], 0
        
        for p in prices:
            low = min(low, p)
            profit = max(p-low, profit)
        return profit