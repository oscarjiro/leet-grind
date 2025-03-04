class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        powersOfThrees: list[int] = [1]
        power: int = 1
        
        while power < n:
            power *= 3
            powersOfThrees.append(power)

        reversedPowers: list[int] = list(reversed(powersOfThrees))
        for i in range(len(reversedPowers)):
            temp: int = n
            for j in range(i, len(reversedPowers)):
                if temp - reversedPowers[j] == 0:
                    return True
                if temp - reversedPowers[j] > 0:
                    temp -= reversedPowers[j]

        return False