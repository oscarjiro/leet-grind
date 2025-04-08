class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        for (int num : nums)
            ++freq[num];
        
        if (freq.size() == nums.size())
            return 0;
        
        int operations = 0, start = 0;
        while (start < nums.size())
        {
            for (int i = start; i < nums.size() && i < start + 3; ++i)
                --freq[nums[i]];
            ++operations;

            bool all_are_distinct = true;
            for (auto &p : freq)
                if (p.second > 1)
                {
                    all_are_distinct = false;
                    break;
                }
            
            if (all_are_distinct)
                break;
            start += 3;
        }

        return operations;
    }
};