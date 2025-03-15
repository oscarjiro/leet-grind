int minCapability(int* nums, int numsSize, int k) 
{
    int min_reward = 1000000000, max_reward = 1;
    for (int i = 0; i < numsSize; ++i)
        min_reward = fmin(min_reward, nums[i]),
        max_reward = fmax(max_reward, nums[i]);

    while (min_reward < max_reward)
    {
        int mid_reward = (min_reward + max_reward) / 2;
        int possible_thefts = 0;

        for (int i = 0; i < numsSize; ++i)
            if (nums[i] <= mid_reward)
                ++possible_thefts, ++i;
        
        if (possible_thefts >= k)
            max_reward = mid_reward;
        else 
            min_reward = mid_reward + 1;
    }

    return min_reward;
}