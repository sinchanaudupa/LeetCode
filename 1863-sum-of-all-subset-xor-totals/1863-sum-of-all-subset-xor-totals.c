int solve(int* nums, int numsSize, int index, int currentXor)
{
    if (index == numsSize)
    {
        return currentXor;
    }
    int include = solve(nums, numsSize, index + 1,
                        currentXor ^ nums[index]);
    int exclude = solve(nums, numsSize, index + 1,
                        currentXor);
    return include + exclude;
}

int subsetXORSum(int* nums, int numsSize)
{
    return solve(nums, numsSize, 0, 0);
}