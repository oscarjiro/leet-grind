#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution 
{
public:
    int minimumRecolors(string blocks, int k) 
    {
        fast_io;
        
        int min_recolors = 0;
        for (int i = 0; i < k; ++i)
            if (blocks[i] == 'W')
                ++min_recolors;

        int recolors = min_recolors;
        for (int i = 1; i <= blocks.size() - k; ++i)
        {
            if (blocks[i - 1] == 'W')
                --recolors;
            if (blocks[i + k - 1] == 'W')
                ++recolors;
            min_recolors = min(min_recolors, recolors);
        }

        return min_recolors;
    }
};