class Solution:
    def findMissingAndRepeatedValues(self, grid: list[list[int]]) -> list[int]:
        # Actual sum of all numbers and squared numbers in grid
        actual_sum: int = sum(num for row in grid for num in row)
        actual_sqr_sum: int = sum(num ** 2 for row in grid for num in row)

        # Sum of n natural numbers: [n(n+1)]/2
        # Sum of n squared natural numbers: [n(n+1)(2n+1)]/6
        n: int = len(grid) ** 2
        perfect_sum: int = n * (n + 1) // 2
        perfect_sqr_sum: int = n * (n + 1) * (2 * n + 1) // 6

        # BREAKING DOWN EXPRESSIONS
        # a: repeat occurences, b: missing
        # actual_sum = perfect_sum + a - b
        # sum_diff = a - b
        # actual_sqr_sum = perfect_sqr_sum + a^2 - b^2
        # sum_sqr_diff = a^2 - b^2
        # a^2 - b^2 = (a+b)(a-b)
        # sum_sqr_diff = (a+b) * sum_diff
    
        # SUB & ELIMINATION TO FIND REPEAT & MISSING
        # a + b = sum_sqr_diff / sum_diff
        # a - b = sum_diff
        # a = [(sum_sqr_diff / sum_diff) + sum_diff]/2
        # b = [(sum_sqr_diff / sum_diff) - sum_diff]/2

        sum_diff: int = actual_sum - perfect_sum
        sum_sqr_diff: int = actual_sqr_sum - perfect_sqr_sum
        
        repeat: int = (sum_sqr_diff // sum_diff + sum_diff) // 2
        missing: int = (sum_sqr_diff // sum_diff - sum_diff) // 2
        
        return [repeat, missing]


