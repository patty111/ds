class Solution:
    def firstUniqChar(self, s: str) -> int:
        tmp = defaultdict(int)

        for i in s:
            tmp[i] += 1

        idx = -1
        for i in s:
            if tmp[i] == 1:
                return idx + 1
            else:
                idx += 1

        return -1