class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        max_len, bitmask, l = 1, 0, 0
        for r in range(len(nums)):
            while nums[r] & bitmask:
                bitmask ^= nums[l]
                l += 1
            max_len = max(max_len, r - l + 1)
            bitmask |= nums[r]
        return max_len


