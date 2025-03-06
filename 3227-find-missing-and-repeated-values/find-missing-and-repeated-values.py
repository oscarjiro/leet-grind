class Solution:
    def findMissingAndRepeatedValues(self, grid: list[list[int]]) -> list[int]:
        ans: list[int] = [-1, -1]
        count_dict: dict[int, int] = {i: 0 for i in range(1, len(grid) * len(grid) + 1)}

        for g in grid:
            for num in g:
                count_dict[num] += 1
                if count_dict[num] == 2:
                    ans[0] = num
        
        for num, count in count_dict.items():
            if count == 0:
                ans[1] = num
                break
        
        return ans