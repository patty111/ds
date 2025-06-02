class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.history_head = 0

    def visit(self, url: str) -> None:
        self.history = self.history[:self.history_head + 1]
        self.history.append(url)
        self.history_head += 1

    def back(self, steps: int) -> str:
        self.history_head = max(0, self.history_head - steps)
        return self.history[self.history_head]

    def forward(self, steps: int) -> str:
        self.history_head = min(len(self.history) - 1, self.history_head + steps)
        return self.history[self.history_head]
