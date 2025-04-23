#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution 
{
public:
    int countLargestGroup(int n) 
    {
        fast_io;

        int largest_size = 1;
        unordered_map<int, int> sums;
        for (int i = 1; i <= n; ++i)
            largest_size = fmax(largest_size, ++sums[sum_digits(i)]);

        if (largest_size == 1)
            return sums.size();

        int ans = 0;
        for (const auto &p : sums)
            if (p.second == largest_size)
                ++ans;

        return ans;
    }

private:
    int sum_digits(int n) 
    {
        int sum = 0;
        while (n > 0)
            sum += n % 10, n /= 10;
        return sum;
    }
};