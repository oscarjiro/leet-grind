int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}


int minOperations(int** grid, int gridSize, int* gridColSize, int x) 
{
    int n = gridSize * (*gridColSize), nums[n] = {};
    for (int i = 0; i < gridSize; ++i)
        for (int j = 0; j < *gridColSize; ++j)
        {
            if (grid[i][j] % x != grid[0][0] % x)
                return -1;
            nums[i * (*gridColSize) + j] = grid[i][j];
        }
    
    qsort(nums, n, sizeof(int), compare); 
    int median = nums[n / 2 - (n % 2 == 0)];

    int operations = 0;
    for (int i = 0; i < n; ++i)
        operations += abs(nums[i] - median) / x;
    
    return operations;
}