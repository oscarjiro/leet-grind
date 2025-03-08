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
        primes: list[bool] = self.sieve(right)

        ans: list[int] = [-1, -1]
        min_delta: int = 0

        i, j = left, left + 1
        while j <= right:
            if primes[i] and primes[j]:
                current_delta: int = j - i
                if (
                    ans[0] == -1
                    or ans[0] != -1
                    and (current_delta < delta or (current_delta == delta and i < ans[0]))
                ):
                    ans[0] = i
                    ans[1] = j
                    delta = current_delta
                i += 1
                j += 1
                continue
            if not primes[j]:
                j += 1
            if not primes[i]:
                i += 1
                if i == j:
                    j += 1

        return ans