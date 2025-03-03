class Solution:
    def pivotArray(self, nums: list[int], pivot: int) -> list[int]:
        less: list[int] = []
        greater: list[int] = []
        equal: int = 0
        
        for num in nums:
            if num < pivot:
                less.append(num)
            elif num > pivot:
                greater.append(num)
            else:
                equal += 1

        i: int = 0
        for num in less:
            nums[i] = num
            i += 1
        
        for _ in range(equal):
            nums[i] = pivot
            i += 1
        
        for num in greater:
            nums[i] = num
            i += 1
        
        return nums
    