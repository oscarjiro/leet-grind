class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        powersOfThrees: list[int] = [1]
        power: int = 1
        
        while power < n:
            power *= 3
            powersOfThrees.append(power)

        for num in reversed(powersOfThrees):
            if n - num == 0:
                return True
            if n - num > 0:
                n -= num

        return False