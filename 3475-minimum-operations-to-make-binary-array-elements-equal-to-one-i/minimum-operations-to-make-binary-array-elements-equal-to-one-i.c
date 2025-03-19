int minOperations(int* nums, int numsSize) 
{
    int n = 0;
    for (int i = 0; i < numsSize - 2; ++i)
        if (!nums[i])
            ++n,
            nums[i] = 1,
            nums[i + 1] ^= 1,
            nums[i + 2] ^= 1;    
    return nums[numsSize - 1] && nums[numsSize - 2] ? n : -1;
}