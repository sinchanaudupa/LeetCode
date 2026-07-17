/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i=0;
    int j=digitsSize-1;
    if(digits[j]==9)
    {
        while(j>=0&&digits[j]==9)
        {
            digits[j]=0;
            j--;
        }
        if(j<0)
        {
            int *arr = (int *)malloc((digitsSize + 1) * sizeof(int));
            arr[0]=1;
            for(int k=1;k<digitsSize+1;k++)
            {
                arr[k]=0;
            }
            *returnSize = digitsSize + 1;
            return arr;
        }
        digits[j]++;

    }
    else 
    {
        digits[j]++;
    }
       *returnSize = digitsSize;
    return digits;
}