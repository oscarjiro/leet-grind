#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        fast_io;

        int n = grid.size() * grid[0].size();
        if (n == 1)
            return 0;

        vector<int> nums;
        for (const auto &row : grid)
            for (int num : row)
            {
                if (num % x != grid[0][0] % x)
                    return -1;
                nums.push_back(num);
            }
        sort(nums.begin(), nums.end());

        int operations = 0, prefix_index = 0, suffix_index = n - 1;
        while (prefix_index < suffix_index) 
            if (prefix_index < n - suffix_index - 1) 
            {
                int prefix_operations =
                    (prefix_index + 1) *
                    (nums[prefix_index + 1] - nums[prefix_index]) / x;

                operations += prefix_operations;
                ++prefix_index;
            } 
            else 
            {
                int suffix_operations =
                    (n - suffix_index) *
                    (nums[suffix_index] - nums[suffix_index - 1]) / x;

                operations += suffix_operations;
                --suffix_index;
            }

        return operations;
    }
};