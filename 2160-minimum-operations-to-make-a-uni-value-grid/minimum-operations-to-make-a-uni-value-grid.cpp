#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution 
{
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        fast_io;

        int n = grid.size() * grid[0].size();
        if (n == 1)
            return 0;

        vector<int> sorted;
        for (const auto &row : grid)
            for (int num : row)
            {
                if (num % x != grid[0][0] % x)
                    return -1;
                sorted.push_back(num);
            }

        nth_element(sorted.begin(), sorted.begin() + n / 2, sorted.end());
        int median = sorted[n / 2];

        int operations = 0;
        for (const auto &row : grid)
            for (int num : row)
                operations += abs(num - median) / x;
        
        return operations;
    }
};
