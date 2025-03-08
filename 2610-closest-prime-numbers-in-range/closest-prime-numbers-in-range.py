class Solution:
    def sieve(self, n: int) -> list[bool]:
        primes: list[bool] = (n + 1) * [True]
        primes[0] = primes[1] = False
        
        for i in range(2, int(n**0.5) + 1):
            if primes[i]:
                for j in range(i * i, n + 1, i):
                    primes[j] = False
    
        return primes

    def closestPrimes(self, left: int, right: int) -> list[int]:
        all_primes: list[bool] = self.sieve(right)
        primes: list[bool] = [i for i in range(left, right + 1) if all_primes[i]]

        if len(primes) < 2:
            return [-1, -1]

        ans: list[int] = [primes[0], primes[1]]
        min_delta: int = primes[1] - primes[0]

        for i in range(1, len(primes) - 1):
            delta: int = primes[i + 1] - primes[i]
            if delta < min_delta:
                ans[0] = primes[i]
                ans[1] = primes[i + 1]
                if delta == 2:
                    break

        return ans