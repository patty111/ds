class Solution:
    def maxProfit(self,prices):
        left = 0
        max_profit = 0

        for right in range(1, len(prices)):
            max_profit = max_profit if max_profit > (prices[right] - prices[left]) else (prices[right] - prices[left])
            if prices[left] > prices[right]:
                left = right


        return max_profit