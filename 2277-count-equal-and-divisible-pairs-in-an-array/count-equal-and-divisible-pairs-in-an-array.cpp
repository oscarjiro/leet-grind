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

        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); ++i)
            indices[nums[i]].push_back(i);
        
        if (indices.size() == nums.size())
            return 0;
        
        int count = 0;
        for (const auto &p : indices)
        {
            vector<int> arr = p.second;
            if (arr.size() <= 1)
                continue;
            for (int i = 0; i < arr.size() - 1; ++i)
            {
                if (arr[i] % k == 0)
                {
                    count += arr.size() - 1 - i;
                    continue;
                }
                for (int j = i + 1; j < arr.size(); ++j)
                {
                    if ((arr[i] * arr[j]) % k == 0)
                        ++count;
                }
            }
        }

        return count;
    }
};