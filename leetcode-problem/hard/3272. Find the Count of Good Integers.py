import math
from collections import Counter

class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        half_len = (n + 1) // 2
        start = 10 ** (half_len - 1)
        end = 10 ** half_len
        seen = set()
        total = 0

        for num in range(start, end):
            first_half = str(num)
            second_half = first_half[::-1] if n % 2 == 0 else first_half[:-1][::-1]
            palindrome = first_half + second_half
            if int(palindrome) % k != 0:
                continue
            sorted_digits = ''.join(sorted(palindrome))
            if sorted_digits in seen:
                continue
            seen.add(sorted_digits)
            count = Counter(palindrome)
            permutations = math.factorial(n)
            for freq in count.values():
                permutations //= math.factorial(freq)
            if count['0'] > 0:
                permutations -= math.factorial(n - 1)
                for digit, freq in count.items():
                    if digit == '0':
                        permutations //= math.factorial(freq - 1)
                    else:
                        permutations //= math.factorial(freq)
            total += permutations

        return total
