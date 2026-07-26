int* selfDividingNumbers(int left, int right, int* returnSize) 
{
    int* result = malloc((right - left + 1) * sizeof(int));
    *returnSize = 0;

    for (int i = left; i <= right; i++)
    {
        int num = i;
        int valid = 1;

        while (num > 0)
        {
            int digit = num % 10;

            if (digit == 0 || i % digit != 0)
            {
                valid = 0;
                break;
            }

            num = num / 10;
        }

        if (valid)
        {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }

    return result;
}