#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        fast_io;

        int threshold = nums.size() / 2;

        unordered_map<int, int> freq;
        for (int num : nums)
            if (++freq[num] > threshold)
                return num;
        
        int ans = nums[0];
        for (const auto &[num, count] : freq)
            if (count > threshold)
            {
                ans = num;
                break;
            }
        
        return ans;
    }
};