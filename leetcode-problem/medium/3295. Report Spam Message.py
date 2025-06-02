class Solution:
    def reportSpam(self, message: List[str], bannedWords: List[str]) -> bool:
        bannedWords = set(bannedWords)
        counter = 0
        for i in message:
            if i in bannedWords:
                counter += 1
                if counter >= 2:
                    return True
                
        return False