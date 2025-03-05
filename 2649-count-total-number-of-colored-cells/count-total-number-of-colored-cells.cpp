#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution 
{
public:
    long long coloredCells(int n) 
    {
        fast_io;
        return 1 + 2 * (long long)n * (n - 1);
    }
};