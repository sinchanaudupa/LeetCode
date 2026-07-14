/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int *num = malloc(sizeof(int) * (nums1Size + nums2Size));

    int i = 0;
    int k = 0;

    while(i < nums1Size)
    {
        int j = 0;
        int found = 0;

        // Check if nums1[i] exists in nums2
        while(j < nums2Size)
        {
            if(nums1[i] == nums2[j])
            {
                found = 1;
                break;
            }
            j++;
        }

        // If found, check duplicate in answer array
        if(found)
        {
            int m = 0;

            while(m < k)
            {
                if(num[m] == nums1[i])
                {
                    break;
                }
                m++;
            }

            // Not already present
            if(m == k)
            {
                num[k] = nums1[i];
                k++;
            }
        }

        i++;
    }

    *returnSize = k;

    return num;
}