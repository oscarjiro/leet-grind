class Solution 
{
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        int n = grid.size() * grid[0].size();
        if (n == 1)
            return 0;

        int remainder = -1;
        vector<int> sorted;
        for (const auto &row : grid)
            for (int num : row)
            {
                sorted.push_back(num);
                if (remainder == -1)
                    remainder = num % x;
                else if (num % x != remainder)
                    return -1;
            }

        sort(sorted.begin(), sorted.end());
        int median = sorted[n / 2 - (n % 2 == 0)];

        int operations = 0;
        for (const auto &row : grid)
            for (int num : row)
            {
                if (num == median)
                    continue;
                operations += abs(num - median) / x;
            }
        
        return operations;
    }
};
