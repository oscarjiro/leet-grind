class Solution:
    def maximumCount(self, nums: list[int]) -> int:
        neg: int = 0
        nol: int = 0

        for num in nums:
            if num < 0:
                neg += 1
            elif num > 0:
                break
            else:
                nol += 1
        
        return max(neg, len(nums) - neg - nol)