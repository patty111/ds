class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        x = 0
        y = 0

        for i in commands:
            if i == 'RIGHT':
                x += 1
            elif i == 'LEFT':
                x -= 1
            elif i == "DOWN":
                y += 1
            elif i == 'UP':
                y -= 1
        return (y * n) + x