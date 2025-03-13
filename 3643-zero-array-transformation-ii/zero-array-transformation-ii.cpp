#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution 
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>>& queries) 
    {
        fast_io;
        
        int l = 0, r = queries.size();
        if (!is_zero_array(nums, queries, r))
            return -1;
        
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (is_zero_array(nums, queries, m))
                r = m - 1;
            else
                l = m + 1;
        }

        return l;
    }

    bool is_zero_array(vector<int>& nums, vector<vector<int>>& queries, int queryRange)
    {
        vector<int> diff(nums.size() + 1, 0);
        int sum = 0;

        for (int i = 0; i < queryRange; ++i)
            diff[queries[i][0]] += queries[i][2], 
            diff[queries[i][1] + 1] -= queries[i][2];

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += diff[i];
            if (sum < nums[i])
                return false;
        }   

        return true;
    }
};