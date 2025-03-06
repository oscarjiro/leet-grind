/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) 
{
    // Calculate actual sum of numbers and squared numbers in grid
        int actual_sum = 0;
        long long actual_sqr_sum = 0;
        for (int i = 0; i < gridSize; ++i)
            for (int j = 0; j < *gridColSize; ++j)
                actual_sum += grid[i][j], actual_sqr_sum += grid[i][j] * grid[i][j];
        
        // Calculate expected sum of numbers and squared numbers in grid
        // sum of n natural numbers = [n(n+1)]/2
        // sum of n squared natural numbers = [n(n+1)(2n+1)]/6
        int n = gridSize * gridSize;
        int perfect_sum = n * (n + 1) / 2;
        long long perfect_sqr_sum = (long long)n * (n + 1) * (2 * (long long)n + 1) / 6;
        
        // Breaking down expressions
        // ==================================================
        // a = repeat occurence, b = missing number
        // actual_sum = perfect_sum + a - b
        // actual_sqr_sum = perfect_sqr_sum + a^2 - b^2
        // sum_diff = a - b
        // sqr_sum_diff = a^2 - b^2
        // (a+b)(a-b) = a^2 - b^2
        // (a+b) * sum_diff = sqr_sum_diff
        // a + b = sqr_sum_diff / sum_diff
        
        // Substitution & elimination for a & b
        // ==================================================
        // a + b = sqr_sum_diff / sum_diff
        // a - b = sum_diff
        // a     = [(sqr_sum_diff / sum_diff) + sum_diff]/2
        //     b = [(sqr_sum_diff / sum_diff) - sum_diff]/2

        int sum_diff = actual_sum - perfect_sum;
        long long sqr_sum_diff = actual_sqr_sum - perfect_sqr_sum;

        *returnSize = 2;
        int *answer = malloc(sizeof(int) * *returnSize);
        answer[0] = (sqr_sum_diff / sum_diff + sum_diff) / 2;
        answer[1] = (sqr_sum_diff / sum_diff - sum_diff) / 2; 

        return answer;
}