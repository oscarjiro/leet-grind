class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = 0
        for i in range(len(nums) - 2):
            if nums[i] == 0:
                nums[i] = 1
                nums[i + 1] = abs(nums[i + 1] - 1) 
                nums[i + 2] = abs(nums[i + 2] - 1) 
                n += 1

        for num in nums:
            if num == 0:
                return -1

        return n
