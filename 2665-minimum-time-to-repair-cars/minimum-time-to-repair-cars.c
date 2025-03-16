long long repairCars(int* ranks, int ranksSize, int cars) 
{
    int ranks_freq[101] = {};
    int min_rank = 100, max_rank = 1;
    for (int i = 0; i < ranksSize; ++i)
        ++ranks_freq[ranks[i]],
        min_rank = fmin(min_rank, ranks[i]),
        max_rank = fmax(max_rank, ranks[i]);
    
    long long l = 1, h = (long long)max_rank * cars * cars;
    while (l < h)
    {
        long long m = (l + h) / 2;
        long long cars_repaired = 0;

        for (int rank = 1; rank <= max_rank; ++rank)
            cars_repaired += ranks_freq[rank] * (long long)sqrt(m / (long long)rank);
        
        if (cars_repaired >= cars)
            h = m;
        else
            l = m + 1;
    }

    return l;
}