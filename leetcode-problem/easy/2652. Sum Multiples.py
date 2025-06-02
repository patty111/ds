class Solution:
    def sumOfMultiples(self, n: int) -> int:
        ls = []
        for i in range(1, n+1):
            if i % 3 == 0:
                ls.append(i)
                continue
            if i % 5 == 0:
                ls.append(i)
                continue
            if i % 7 == 0:
                ls.append(i)
        return sum(ls)