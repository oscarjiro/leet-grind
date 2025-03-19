/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    let n = 0;
    for (let i = 0; i < nums.length - 2; ++i)
        if (!nums[i]) 
            ++n,
            nums[i] = 1,
            nums[i + 1] ^= 1,
            nums[i + 2] ^= 1;
    return nums.at(-1) && nums.at(-2) ? n : -1;
};