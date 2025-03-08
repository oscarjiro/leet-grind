class Solution 
{
public:
    int minimumRecolors(string blocks, int k) 
    {
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