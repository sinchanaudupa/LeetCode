int findGCD(int* nums, int numsSize) {
    
    int i = 0;
    int min = 100000;
    int max = 0;

    while (i < numsSize)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }

        if (nums[i] > max)
        {
            max = nums[i];
        }

        i++;
    }

    int k = 1;
    int gcd = 1;

    while (k <= min)
    {
        if (min % k == 0 && max % k == 0)
        {
            gcd = k;
        }

        k++;
    }

    return gcd;
}