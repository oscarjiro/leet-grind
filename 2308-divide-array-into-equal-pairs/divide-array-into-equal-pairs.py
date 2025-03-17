from collections import Counter

class Solution:
    def divideArray(self, nums: list[int]) -> bool:
        return all(freq % 2 == 0 for freq in Counter(nums).values())