class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        l_paren = ['(', '[', '{']
        r_paren = [')', ']', '}']

        for i in s:
            if i in l_paren:
                stack.append(i)
            if i in r_paren:
                if len(stack) == 0:
                    return False
                latest = stack.pop()
                if r_paren[l_paren.index(latest)] != i:
                    return False
        if len(stack) > 0:
            return False
        else:
            return True