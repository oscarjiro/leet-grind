class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        power: int = 1
        while power <= n:
            power *= 3
        
        while power > 0:
            if n == power:
                return True
            if n > power:
                n -= power
            power /= 3
            
        return False