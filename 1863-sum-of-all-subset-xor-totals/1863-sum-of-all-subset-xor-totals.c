int subsetXORSum(int* nums, int numsSize)
{
    int allBits = 0;
    for (int i = 0; i < numsSize; i++) {
        allBits |= nums[i];
    }
    return allBits * (1 << (numsSize - 1));
}