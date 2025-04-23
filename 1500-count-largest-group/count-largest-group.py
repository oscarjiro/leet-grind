class Solution:
    def countLargestGroup(self, n: int) -> int:
        sums_count: list[int] = [0] * 37
        largest_size = 1
        ans = 0

        for i in range(1, n + 1):
            sum = self.sum_digits(i)
            sums_count[sum] += 1
            largest_size = max(largest_size, sums_count[sum])
        
        for i in range(1, 37):
            if largest_size == sums_count[i]:
                ans += 1
        
        return ans
        
    def sum_digits(self, n: int) -> int:
        sum = 0
        while n > 0:
            sum += n % 10
            n //= 10
        return sum