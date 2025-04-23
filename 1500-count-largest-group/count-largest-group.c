int sum_digits(int n)
{
    int sum = 0;
    while (n > 0)
        sum += n % 10, n /= 10;
    return sum;
}

int countLargestGroup(int n) 
{
    int sums_count[37] = {};
    int largest_size = 1, ans = 0;

    for (int i = 1; i <= n; ++i)
        largest_size = fmax(largest_size, ++sums_count[sum_digits(i)]);

    for (int i = 1; i <= 36; ++i)
        if (sums_count[i] == largest_size)
            ++ans;

    return ans;
}