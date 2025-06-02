class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        transaction1, transaction2 = float('inf'), float('inf')
        profit1, profit2 = 0, 0

        for i in prices:
            transaction1 = min(transaction1, i)
            profit1 = max(profit1, i - transaction1)

            transaction2 = min(transaction2, i-profit1)
            profit2 = max(profit2, i - transaction2)
        return profit2