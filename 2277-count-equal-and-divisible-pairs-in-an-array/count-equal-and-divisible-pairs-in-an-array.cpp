class Solution 
{
public:
    int countPairs(vector<int>& nums, int k) 
    {
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); ++i)
            indices[nums[i]].push_back(i);
        
        if (indices.size() == nums.size())
            return 0;
        
        int count = 0;
        for (const auto &p : indices)
        {
            if (p.second.size() <= 1)
                continue;
            for (int i = 0; i < p.second.size() - 1; ++i)
            {
                if (p.second[i] % k == 0)
                {
                    count += p.second.size() - 1 - i;
                    continue;
                }
                for (int j = i + 1; j < p.second.size(); ++j)
                {
                    if ((p.second[i] * p.second[j]) % k == 0)
                        ++count;
                }
            }
        }

        return count;
    }
};