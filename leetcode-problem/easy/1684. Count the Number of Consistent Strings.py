class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        count = 0
        for i in words:
            flag = 0
            tmp = set(i)
            for j in tmp:
                if j in allowed:
                    continue
                flag = 1

            if not flag:
                count += 1
        return count