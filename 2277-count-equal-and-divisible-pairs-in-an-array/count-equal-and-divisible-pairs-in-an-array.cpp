#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution 
{
public:
    int countPairs(vector<int>& nums, int k) 
    {   
        fast_io;

        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    ++count;

        return count;
    }
};