int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count=0;
    int max=0;
    int i=0;
    while(i<numsSize)
    {
        if(nums[i]==1)
        {
            count++;
            if(count>max)
            {
                max=count;
            }
        }
        else if(nums[i]==0)
        {
            count=0;
        }
        i++;
    }
    return max;
}