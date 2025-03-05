class Solution:
    def coloredCells(self, n: int) -> int:
        # 1, 4, 8, 12, ..., an
        # 1, 4*1, 4*2, 4*3, ..., 4*(n-1)
        # 1 + 4 * n*(n-1)/2
        # 1 + 2*n*(n-1)
        return 1 + 2 * n * (n - 1)
