class Solution:
    def toLowerCase(self, s: str) -> str:
        res = []
        for i in s:
            if i.isupper():
                res.append(i.lower())
            else:
                res.append(i)
        return ''.join(res)
