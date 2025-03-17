bool divideArray(int* nums, int numsSize) 
{
    int freq[501] = {}, min_num = 500, max_num = 1;
    for (int i = 0; i < numsSize; ++i)
        ++freq[nums[i]], 
        min_num = fmin(min_num, nums[i]), 
        max_num = fmax(max_num, nums[i]);
    for (int i = min_num; i <= max_num; ++i)
        if (freq[i] % 2 != 0)
            return false;
    return true;
}