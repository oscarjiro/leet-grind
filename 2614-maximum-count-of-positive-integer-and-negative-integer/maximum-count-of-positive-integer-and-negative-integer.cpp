class Solution 
{
public:
    int maximumCount(vector<int>& nums) 
    {
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