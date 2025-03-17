int compare(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);  
}

bool divideArray(int* nums, int numsSize) 
{
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize;)
    {
        int freq = 0, current = nums[i];
        while (i < numsSize && nums[i] == current)
            ++freq, ++i;
        if (freq % 2 != 0)
            return false;
    }
    return true;
}