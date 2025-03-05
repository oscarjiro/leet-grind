class Solution:
    def coloredCells(self, n: int) -> int:
        if n == 1: 
            return 1
        n -= 1
        return int(n / 2 * (2 * 4 + (n - 1) * 4) + 1)
