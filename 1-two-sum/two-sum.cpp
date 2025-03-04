#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        fast_io;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if (indices.contains(complement))
                return {indices[complement], i};
            indices[nums[i]] = i;
        }
        return {};
    }
};