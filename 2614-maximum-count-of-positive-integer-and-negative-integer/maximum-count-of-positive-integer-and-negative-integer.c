int maximumCount(int* nums, int numsSize) 
{
    int neg = 0, nol = 0;
    for (int i = 0; i < numsSize && nums[i] <= 0; ++i)
        if (nums[i] < 0)  
            ++neg;
        else
            ++nol;
    return fmax(neg, numsSize - neg - nol);
}