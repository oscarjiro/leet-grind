#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution 
{
public:
    int maximumCount(vector<int>& nums) 
    {
        fast_io;
        int neg = 0, nol = 0;
        for (auto num : nums)
            if (num < 0)
                ++neg;
            else if (num > 0)
                break; 
            else
                ++nol;
        return max(neg, (int)nums.size() - neg - nol);
    }
};