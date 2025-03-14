bool is_zero_array(int *nums, int numsSize, int **queries, int queriesSize, int queryRange)
{
    int diff[numsSize + 1] = {};
    int sum = 0;

    for (int i = 0; i < queryRange; ++i)
        diff[queries[i][0]] += queries[i][2],
        diff[queries[i][1] + 1] -= queries[i][2];

    for (int i = 0; i < numsSize; ++i)
    {
        sum += diff[i];
        if (sum < nums[i])
            return false;
    }

    return true;
}

int minZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) 
{
    int left = 0, right = queriesSize;
    if (!is_zero_array(nums, numsSize, queries, queriesSize, right))
        return -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (is_zero_array(nums, numsSize, queries, queriesSize, mid))
            right = mid - 1;
        else
            left = mid + 1;
    }  

    return left;
}