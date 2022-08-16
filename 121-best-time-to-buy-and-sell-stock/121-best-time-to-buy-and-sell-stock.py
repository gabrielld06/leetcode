class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        low, profit = prices[0], 0
        for p in prices:
            low = p if p < low else low
            profit = p-low if p-low > profit else profit
        return profit