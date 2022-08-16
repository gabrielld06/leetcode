class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        low, profit = prices[0], 0
        for p in prices: low, profit = p if p < low else low, p-low if p-low > profit else profit
        return profit