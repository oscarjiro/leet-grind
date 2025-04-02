class Solution 
{
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        long long max_value = 0;
        for (int i = 0; i < nums.size() - 2; ++i)
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                if (nums[i] <= nums[j])
                    continue;
                int delta = nums[i] - nums[j];
                for (int k = j + 1; k < nums.size(); ++k)
                    max_value = max((long long)delta * nums[k], max_value);
            }
        return max_value;
    }
};