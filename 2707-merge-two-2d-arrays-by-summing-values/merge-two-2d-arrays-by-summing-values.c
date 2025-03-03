/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = 0;
    *returnColumnSizes = malloc((nums1Size + nums2Size) * sizeof(int)); 
    int** merged_nums = malloc((nums1Size + nums2Size) * sizeof(int*)); 

    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) 
    {   
        merged_nums[k] = malloc(2 * sizeof(int)); 
        (*returnColumnSizes)[k] = 2; 

        if (nums1[i][0] < nums2[j][0]) 
        {
            merged_nums[k][0] = nums1[i][0];
            merged_nums[k][1] = nums1[i][1];
            i++;
        } 
        else if (nums1[i][0] > nums2[j][0]) 
        {
            merged_nums[k][0] = nums2[j][0];
            merged_nums[k][1] = nums2[j][1];
            j++;
        } 
        else 
        { 
            merged_nums[k][0] = nums1[i][0];
            merged_nums[k][1] = nums1[i][1] + nums2[j][1];
            i++;
            j++;
        }
        k++;
    }

    while (i < nums1Size) 
    {
        merged_nums[k] = malloc(2 * sizeof(int));
        (*returnColumnSizes)[k] = 2;
        merged_nums[k][0] = nums1[i][0];
        merged_nums[k][1] = nums1[i][1];
        i++, k++;
    }

    while (j < nums2Size) 
    {
        merged_nums[k] = malloc(2 * sizeof(int));
        (*returnColumnSizes)[k] = 2;
        merged_nums[k][0] = nums2[j][0];
        merged_nums[k][1] = nums2[j][1];
        j++, k++;
    }

    *returnSize = k;
    return merged_nums;
}