int maximumCandies(int* candies, int candiesSize, long long k) 
{
    long long total_candies = 0;
    int max_pile = 1;
    for (int i = 0; i < candiesSize; ++i)
        total_candies += candies[i], max_pile = fmax(max_pile, candies[i]);

    if (total_candies < k)
        return 0;
    if (total_candies == k)
        return 1;

    int ans = 1;
    int l = 1, r = max_pile;
    while (l <= r)
    {
        int m = (l + r) / 2;
        long long max_children = 0;
        for (int i = 0; i < candiesSize; ++i)
            max_children += candies[i] / m;
        if (max_children >= k)
            ans = m, l = m + 1;
        else
            r = m - 1;
    }
    
    return ans;
}