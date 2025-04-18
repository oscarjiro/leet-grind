class Solution:
    def countPairs(self, nums: list[int], k: int) -> int:
        return sum(
            1 if nums[i] == nums[j] and (i * j) % k == 0 else 0
            for i in range(len(nums) - 1)
            for j in range(i + 1, len(nums))
        ) 