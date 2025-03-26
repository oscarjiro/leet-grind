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
        vector<int> sorted;
        sorted.reserve(n);
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
        for (int num : sorted)
            operations += abs(num - median) / x;
        
        return operations;
    }
};
