class Solution:
    def minOperations(self, grid: list[list[int]], x: int) -> int:
        if (n := len(grid) * len(grid[0])) == 1:
            return 0

        arr: list[int] = []
        mod: int = -1
        for row in grid:
            for num in row:
                arr.append(num)
                if mod == -1:
                    mod = num % x
                elif num % x != mod:
                    return -1
        
        arr = sorted(arr)
        median: int = arr[n // 2 - (n % 2 == 0)]
        
        return sum(abs(num - median) // x for row in grid for num in row)